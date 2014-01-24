#include "Db/DbManager.h"

#include <QApplication>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>

#include <QDebug>

namespace CE {
DbManager::DbManager()
{
    mDb = QSqlDatabase::addDatabase("QSQLITE", "CodeEditorDb");

    QDir dataDir = QDir(QApplication::applicationDirPath());
    dataDir.cd("data");
    QString databaseFile = dataDir.absoluteFilePath("db.sqllite");

    mDb.setDatabaseName(databaseFile);

    if (!mDb.open()) {
        qWarning() << "DbManager::DbManager(): can't open db";
        qWarning() << mDb.lastError().text();
    }
}

QSqlDatabase DbManager::getDb()
{
    return mDb;
}

QSqlQuery DbManager::query()
{
    QSqlQuery query(mDb);
    query.setForwardOnly(true);

    return query;
}

bool DbManager::exec(QString sql)
{
    return query().exec(sql);
}

}
