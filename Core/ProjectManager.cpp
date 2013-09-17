#include "NewProjectDialog.h"
#include "ProjectManager.h"

#include <QDir>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QDebug>

namespace PHPEditor {

ProjectManager::ProjectManager()
{
    //isShowNewProjectDialog = false;
}

void ProjectManager::showNewProjectDialog()
{
    if (!isShowNewProjectDialog) {
        NewProjectDialog *newProjectDialog = new NewProjectDialog;
        newProjectDialog->show();
        isShowNewProjectDialog = true;
    }
}

void ProjectManager::createNewProject(QString name, QString location)
{
    QDir dataDir = QDir(QApplication::applicationDirPath());
    dataDir.cd("data");
    QFile file(dataDir.absoluteFilePath("projects.json"));

    qDebug() << file.fileName();
    QJsonDocument jsonDocument;
    QJsonArray array;

    if(file.exists()) {
        file.open(QIODevice::ReadWrite | QIODevice::Text);
        QString projectsFile = file.readAll();
        jsonDocument = QJsonDocument::fromJson(projectsFile.toUtf8());
        array = jsonDocument.array();
    }

    QJsonObject object;
    object["name"] = name;
    object["location"] = location;


    array.append(object);
    jsonDocument.setArray(array);


    qDebug() << "json";
    qDebug() << jsonDocument.toJson();
    file.write(jsonDocument.toJson());
    file.close();
}
}
