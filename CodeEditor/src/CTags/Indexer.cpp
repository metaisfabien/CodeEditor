#include "CTags/Indexer.h"
#include "CTags/IndexFile.h"
#include "CTags/IndexStorage.h"
#include "Project/Project.h"

#include <QFileInfo>
#include <QDir>
#include <QDebug>

extern "C" {
    #include "exuberantCtags.h"
}


#include <QProcess>

namespace CE {
CTagsIndexer::CTagsIndexer(CTagsIndexStorage *storage)
{
    mStorage = storage;
    initCtags();
      //  TagEntryListItem* item = createTagEntryListItem( filePath.toLocal8Bit().constData(), 0 );
}

void CTagsIndexer::addProject(Project *project)
{
    mProjectToIndex.append(project);
}

void CTagsIndexer::indexProject(Project *project)
{
    parseDir(project->getLocation(), project);
}

void CTagsIndexer::parseDir(QString dirPath, Project *project)
{
    QDir dir = QDir(dirPath);
    foreach (QString entryName, dir.entryList(QDir::NoFilter, QDir::DirsFirst)) {
        if (entryName != "." && entryName != "..") {
             QString fileName = dirPath + "/" + entryName;

             if (canIndexFile(fileName, project)) {
                 mFileToIndex[fileName] = new CTagsIndexFile(fileName, project);
             } else if (QFileInfo(fileName).isDir()) {
                parseDir(dirPath + "/" + entryName, project);
             }
        }
    }
}

bool CTagsIndexer::canIndexFile(QString fileName, Project *project)
{
    QFileInfo fileInfo(fileName);
    return fileInfo.isFile() &&
            !mFileToIndex.contains(fileName) &&
            QFile::exists(fileName) &&
            !fileInfo.suffix().isEmpty() &&
            !mStorage->indexExist(fileName, project);
}

void CTagsIndexer::run()
{
    for (int i = 0; i < mProjectToIndex.size(); ++i) {
        Project *project = mProjectToIndex.at(i);
        parseDir(project->getLocation(), project);
    }

    QMap<QString, CTagsIndexFile*> fileToIndex = mFileToIndex;
    mFileToIndex.clear();
    //emit indexingStarted();
    foreach (QString key, fileToIndex.keys()) {
        CTagsIndexFile* _indexFile = fileToIndex[key];
        indexFile(_indexFile);
       // fileToIndex.remove(key);
    }
}

void CTagsIndexer::indexFile(CTagsIndexFile* indexFile)
{
    TagEntryListItem *tag = createTagEntryListItem(indexFile->getFileName().toLocal8Bit().constData(), 0 );
    int projectId = indexFile->getProject()->getId();
    mStorage->createTag(projectId, indexFile->getFileName(), tag);

    //indexFile->setTagEntryListItem(tagEntryListItem);
    qDebug() << "index " << indexFile->getFileName();
}

}
