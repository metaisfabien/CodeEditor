#ifndef CTAGS_INDEXDBSTORAGE_H
#define CTAGS_INDEXDBSTORAGE_H

#include "CTags/IndexStorage.h"

#include <QSqlDatabase>

namespace CE {
class CTagsIndexDbStorage : public CTagsIndexStorage
{
    public:
        CTagsIndexDbStorage();
        virtual bool indexExist(QString fileName, Project *project);
        virtual bool createTag(int projectId, QString fileName, TagEntryListItem *tag);

    protected:
        int insertTagFile(const int projectId, const QString& fileName, const QString& language);
        void insertTags(const int fileId, TagEntryListItem *tag);

        void checkTables();
        QSqlQuery query();

        QSqlDatabase mDb;
};
}

#endif // CTAGS_INDEXDBSTORAGE_H
