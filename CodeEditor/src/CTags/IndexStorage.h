#ifndef CTAGS_INDEXSTORAGE_H
#define CTAGS_INDEXSTORAGE_H

#include <QString>

extern "C" {
    #include "exuberantCtags.h"
}

namespace CE {
class Project;
class CTagsIndexStorage
{
    public:
        virtual bool indexExist(QString fileName, Project *project) = 0;
        virtual bool createTag(int projectId, QString fileName, TagEntryListItem *tag) = 0;
};
}

#endif // CTAGS_INDEXSTORAGE_H
