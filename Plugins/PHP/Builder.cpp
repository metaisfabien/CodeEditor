#include "Builder.h"
#include "Project/Project.h"

#include <QDir>
#include <QFileInfo>
#include <QDebug>


namespace CE {
namespace PHP {

Builder::Builder()
{

}

void Builder::build(Project *project)
{
    qDebug() << "Build project " << project->getName();
    parseDir(project->getLocation());
   // project->setIsBuild(true);
}

void Builder::parseDir(QString dirPath)
{
    QDir dir = QDir(dirPath);
    foreach (QString entryName, dir.entryList(QDir::NoFilter, QDir::DirsFirst)) {
        if (entryName != "." && entryName != "..") {
             QFileInfo fileInfo(dirPath + "/" + entryName);
             if (fileInfo.isFile()) {
                 parseFile(dirPath + "/" + entryName);
             } else {
                // parseDir(dirPath + "/" + entryName);
             }
        }
    }
}

void Builder::parseFile(QString filePath)
{
    qDebug() << "parseFile " << filePath;
    QString fileContent = getFileContent(filePath);

  //  TagEntryListItem* item = createTagEntryListItem( filePath.toLocal8Bit().constData(), 0 );

    qDebug() << "test";
   // token_get_all(fileContent);
    /**QRegExp regExp ("#<\?php(.+?)?>#s");
    QStringList phpScripts = regExp.capturedTexts();**/
}

QString Builder::getFileContent(QString filePath)
{
    QFile file(filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    return file.readAll();
}

}
}
