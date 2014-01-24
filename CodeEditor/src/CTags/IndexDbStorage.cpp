#include "CTags/IndexDbStorage.h"
#include "Db/DbManager.h"
#include "Project/Project.h"
#include "CodeEditor.h"

#include <QStringList>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

namespace CE {
CTagsIndexDbStorage::CTagsIndexDbStorage()
{
    checkTables();
}

void CTagsIndexDbStorage::checkTables()
{
    DbManager *dbManager = CodeEditor::getDbManager();

    if (!dbManager->getDb().tables().contains("ctags_index", Qt::CaseInsensitive)) {
        const QString sqlIndex = QString(
            "CREATE TABLE 'main'.'ctags_tag' ("
            "'id' INTEGER PRIMARY KEY AUTOINCREMENT,"
            "'file_id' INTEGER NOT NULL,"
            "'line_number_entry' INTEGER NOT NULL,"
            "'line_number' INTEGER NOT NULL,"
            "'is_file_scope' INTEGER NOT NULL,"
            "'is_file_entry' INTEGER NOT NULL,"
            "'truncate_line' INTEGER NOT NULL,"
            "'name' TEXT NOT NULL,"
            "'kind' INTEGER NOT NULL,"
            "'access' TEXT,"
            "'file_scope' TEXT,"
            "'implementation' TEXT,"
            "'inheritance' TEXT,"
            "'scope_value' TEXT,"
            "'scope_key' TEXT,"
            "'signature' TEXT,"
            "'type' TEXT,"
            "'type_name' TEXT"
            ");"
        );
        dbManager->query().exec(sqlIndex);
    }

    if (!dbManager->getDb().tables().contains("ctags_files", Qt::CaseInsensitive)) {
        const QString sqlFiles = QString(
            "CREATE TABLE 'main'.'ctags_file' ("
            "'id' INTEGER PRIMARY KEY AUTOINCREMENT,"
            "'project_id' INTEGER NOT NULL,"
            "'file_name' TEXT NOT NULL,"
            "'language' TEXT NOT NULL"
            ");"
        );
        dbManager->query().exec(sqlFiles);

        const QString sqlFilesTrigger = QString(
            "CREATE TRIGGER 'files_after_delete' AFTER DELETE ON 'ctags_file' FOR EACH ROW\n"
            "BEGIN\n"
            "DELETE FROM 'ctags_index' WHERE 'ctags_tag'.'file_id' = 'old'.'id';\n"
            "END;"
        );
        dbManager->query().exec(sqlFilesTrigger);

        const QString sqlFilesProjectIdAsc = QString(
            "CREATE INDEX 'files_filename_asc' on 'ctags_file' (project_id ASC)"
        );
        dbManager->query().exec(sqlFilesProjectIdAsc);

        const QString sqlFilesFileNameAsc = QString(
            "CREATE INDEX 'files_filename_asc' on 'ctags_file' (file_name ASC)"
        );
        dbManager->query().exec(sqlFilesFileNameAsc);


    }
}

bool CTagsIndexDbStorage::indexExist(QString fileName, Project *project)
{
    const QString sql = QString("SELECT id FROM ctags_file WHERE project_id = ? AND file_name = ?");
    QSqlQuery query = CodeEditor::getDbManager()->query();

    query.prepare(sql);
    query.addBindValue(project->getId());
    query.addBindValue(fileName);

    if (!query.exec()) {
        qWarning() << "CTagsIndexDbStorage::indexExist(): Can't exec db query";
        qWarning() << query.lastError().text();
        return false;
    }
    if (query.size() <= 0) {
        return false;
    } else {
        return true;
    }
}

bool CTagsIndexDbStorage::createTag(int projectId, QString fileName, TagEntryListItem *tag)
{
    int fileId = insertTagFile(projectId, fileName, QString::fromLocal8Bit(tag->tag.language));
    insertTags(fileId, tag);

    return true;
}


int CTagsIndexDbStorage::insertTagFile(const int projectId, const QString& fileName, const QString& language)
{
    const QString sql = QString("INSERT INTO ctags_file (project_id, file_name,language) VALUES(?, ?, ?)");
    QSqlQuery query = CodeEditor::getDbManager()->query();

    query.prepare(sql);
    query.addBindValue(projectId);
    query.addBindValue(fileName);
    query.addBindValue(language);

    if (!query.exec()) {
        qWarning() << "CTagsIndexer::insertTagFile(): Can't exec db query";
        qWarning() << query.lastError().text();
        return -1;
    }

    return query.lastInsertId().toInt();
}

void CTagsIndexDbStorage::insertTags(const int fileId, TagEntryListItem *tag)
{
    const QString sql = QString(
        "INSERT INTO ctags_tag "
        "(file_id, line_number_entry, line_number, is_file_scope, is_file_entry, truncate_line, "
        "name, kind, access, file_scope, implementation, inheritance, scope_value, "
        "scope_key, signature, type, type_name ) "
        "VALUES( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ? )"
    );
    QSqlQuery query = CodeEditor::getDbManager()->query();


    while (tag != NULL) {
        tagEntryInfo* entry = &tag->tag;

        query.prepare( sql );
        query.addBindValue(fileId);
        query.addBindValue(entry->lineNumberEntry -1);
        query.addBindValue(QVariant::fromValue(entry->lineNumber -1));
        query.addBindValue(entry->isFileScope);
        query.addBindValue(entry->isFileEntry);
        query.addBindValue(entry->truncateLine);
        query.addBindValue(entry->name);
        query.addBindValue(QChar(entry->kind));
        query.addBindValue(entry->extensionFields.access);
        query.addBindValue(entry->extensionFields.fileScope);
        query.addBindValue(entry->extensionFields.implementation);
        query.addBindValue(entry->extensionFields.inheritance);
        query.addBindValue(entry->extensionFields.scope[0]);
        query.addBindValue(entry->extensionFields.scope[1]);
        query.addBindValue(entry->extensionFields.signature);
        query.addBindValue(entry->extensionFields.typeRef[0]);
        query.addBindValue(entry->extensionFields.typeRef[1]);

        if (!query.exec()) {
            qWarning() << "CTagsIndexer::insertTags error:";
            qWarning() << query.lastError().text();
            return ;
        }

        tag = tag->next;
    }
}

}
