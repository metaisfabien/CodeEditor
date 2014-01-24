#ifndef CTAGS_INDEXFILE_H
#define CTAGS_INDEXFILE_H

#include "Project/Project.h"


extern "C" {
    //#include <exuberantCtags.h>
}
namespace CE {
class CTagsIndexFile
{
public:
    CTagsIndexFile(QString fileName, Project *project)
    {
        mFileName = fileName;
        mProject = project;
    }

    QString getFileName() { return mFileName; }
    Project *getProject() { return mProject; }
   // void setTagEntryListItem(TagEntryListItem *tagEntryListItem) { mTagEntryListItem = tagEntryListItem; }

private:
    QString mFileName;
    Project *mProject;
   // TagEntryListItem *mTagEntryListItem;
};
}
#endif // CTAGS_INDEXER_H
