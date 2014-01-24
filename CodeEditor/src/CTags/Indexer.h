#ifndef CTAGS_INDEXER_H
#define CTAGS_INDEXER_H



#include <QThread>
#include <QMap>


namespace CE {
class CTagsIndexFile;
class CTagsIndexStorage;
class Project;
class CTagsIndexer : public QThread
{
public:
    CTagsIndexer(CTagsIndexStorage *storage);
    void indexProject(Project *project);
    void parseDir(QString dirPath, Project *project);
    void addProject(Project *project);

protected:

    CTagsIndexStorage *mStorage;
    QMap<QString, CTagsIndexFile*> mFileToIndex;
    QList<Project *> mProjectToIndex;
    virtual void run();
    void indexFile(CTagsIndexFile* indexFile);
    bool canIndexFile(QString fileName, Project *project);
};
}
#endif // CTAGS_INDEXER_H
