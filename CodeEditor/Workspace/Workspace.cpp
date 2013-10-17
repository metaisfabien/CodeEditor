#include "Workspace.h"
#include "Perspective.h"
#include "Dock.h"

#include <QDir>
#include <QApplication>
#include <QJsonDocument>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

namespace CE {
Workspace::Workspace()
{
    currentPerspective = 0;
    load();
}

Workspace::~Workspace()
{
    vector<Perspective*>::const_iterator perspectiveIterator;
    for(perspectiveIterator = perspectives.begin(); perspectiveIterator != perspectives.end(); ++perspectiveIterator) {
        delete (*perspectiveIterator);
    }
}

void Workspace::load()
{
    qDebug() << "Load workspace";

    QDir dataDir = QDir(QApplication::applicationDirPath() + "/data");
    if (dataDir.exists()){
        QFile projectsFile(dataDir.absoluteFilePath("workspace.json"));
        if (projectsFile.exists()) {
            projectsFile.open(QIODevice::ReadOnly | QIODevice::Text);
            QString projectsJson = projectsFile.readAll();
            QJsonDocument jsonDocument = QJsonDocument::fromJson(projectsJson.toUtf8());
            QJsonObject workspaceConfig = jsonDocument.object();
            if (workspaceConfig["perspectives"].toArray().count()) {
                loadPerspectives(workspaceConfig["perspectives"].toArray());
            } else {
                qDebug() << "Load workspace perspectives from workspace.json fail";
            }
        } else {
             qDebug() << "workspace.json not exist, load workspace fail";
        }
    } else {
        qDebug() << "data directory not exist, load workspace fail";
    }
}

void Workspace::loadPerspectives(QJsonArray perspectivesArray)
{
    qDebug() << "Load Perspectives";
    for(int i = 0; i < perspectivesArray.count(); i++) {
        QJsonObject perspectiveObject = perspectivesArray[i].toObject();
        Perspective *perspective = new Perspective(perspectiveObject["name"].toString(), perspectiveObject["icone"].toString());
        addDocksToPerpective(perspectiveObject, perspective);
        perspectives.push_back(perspective);
        if (perspectiveObject["current"].toBool()) {
            currentPerspective = perspective;
        }
        // qDebug() << perspectiveObject;
        //perspectiveObject["docks"]

    }
}

Perspective* Workspace::getCurrentPerspective()
{
    return currentPerspective;
}

void Workspace::test()
{
    qDebug() << "test";
}

void Workspace::addDocksToPerpective(QJsonObject perspectiveObject, Perspective* perspective)
{
    QJsonArray docksArray = perspectiveObject["docks"].toArray();
    if (docksArray.count()) {
         for(int i = 0; i < docksArray.count(); i++) {
            QJsonObject dockObject = docksArray[i].toObject();
            Dock *dock = new Dock(dockObject["id"].toString(),dockObject["id"].toString());
            perspective->addDock(dock);
         }

     }
}

}
