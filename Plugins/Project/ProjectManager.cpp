#include "ProjectManager.h"
#include "Project.h"

#include <QDir>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QDebug>
namespace CE {
namespace Project {
ProjectManager::ProjectManager()
{
    loadProjects();
}

ProjectManager::~ProjectManager()
{
    vector<Project*>::const_iterator projectIterator;
    for(projectIterator = projects.begin(); projectIterator != projects.end(); ++projectIterator) {
        delete (*projectIterator);
    }
}

/**
 * @brief ProjectManager::loadProjects
 *
 * Load the projects from the projects.json file
 *
 */
void ProjectManager::loadProjects()
{
    QDir dataDir = QDir(QApplication::applicationDirPath() + "/data");
    if (dataDir.exists()){
        QFile projectsFile(dataDir.absoluteFilePath("projects.json"));
        if (projectsFile.exists()) {
            projectsFile.open(QIODevice::ReadOnly | QIODevice::Text);
            QString projectsJson = projectsFile.readAll();
            QJsonDocument jsonDocument = QJsonDocument::fromJson(projectsJson.toUtf8());
            QJsonArray array = jsonDocument.array();
            for(int i = 0; i < array.count(); i++) {
                QJsonObject projectJsonObject = array[i].toObject();
                Project* project = new Project(projectJsonObject["name"].toString(), projectJsonObject["location"].toString());
                projects.push_back(project);
            }
        }
    }
}

void ProjectManager::createNewProject(QString name, QString location)
{
    qDebug() << "createNewProject" << name << " " << location;

    Project* project = new Project(name, location);
    projects.push_back(project);
    updateProjectsFile();
}

void ProjectManager::updateProjectsFile()
{
    QDir dataDir = QDir(QApplication::applicationDirPath() + "/data");
    if (!dataDir.exists()){
        dataDir.mkdir(".");
    }
    QFile projectsFile(dataDir.absoluteFilePath("projects.json"));

    QJsonDocument jsonDocument;
    QJsonArray array;

    projectsFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);

    vector<Project*>::const_iterator projectIterator;
    for(projectIterator = projects.begin(); projectIterator != projects.end(); ++projectIterator) {
        QJsonObject object;
        object["name"] = (*projectIterator)->getName();
        object["location"] = (*projectIterator)->getLocation();

        array.append(object);
    }

    jsonDocument.setArray(array);

    projectsFile.write(jsonDocument.toJson());
    projectsFile.close();

    qDebug() << "Project file updated: " << jsonDocument.toJson();
}

/**
 * @brief ProjecrManager::getProjects
 *
 * Return the projects vector
 *
 * @return vector<Project*>
 */
vector<Project*> ProjectManager::getProjects() const
{
    return projects;
}
}
}
