#include "Project/ProjectManager.h"
#include "Project/Project.h"
#include "Project/ProjectExplorerDock.h"
#include "Project/Tree/View.h"
#include "Project/NewProjectDialog.h"

#include "Action/Manager.h"
#include "Menu/MenuBar.h"
#include "Theme/ThemeManager.h"

#include "Db/DbManager.h"
#include "Dock/DockManager.h"

#include "CTags/IndexDbStorage.h"
#include "CTags/Indexer.h"

#include "MainWindow.h"
#include "CodeEditor.h"

#include <QDir>
#include <QApplication>

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

#include <QDebug>

namespace CE {
ProjectManager::ProjectManager()
{
    //Create New project action
    QAction *newProjectAction = CodeEditor::getActionManager()->createAction(QString("new_project"), tr("&Project"), CodeEditor::getThemeManager()->getIcon("project.png"));
    newProjectAction->setStatusTip(tr("New project"));
    QObject::connect(newProjectAction, SIGNAL(triggered()), this, SLOT(showNewProjectDialog()));

    //@TODO: add this to a menubar manager to let user configure the manus
    QMenu *newFileMenu = CodeEditor::getMainWindow()->menuBar()->menu("file/new", tr("&New"));
    newFileMenu->addAction(newProjectAction);

    checkDb();
    CTagsIndexDbStorage *indexStorage = new CTagsIndexDbStorage;
    mCTagsIndexer = new CTagsIndexer(indexStorage);

    loadProjects();

    CodeEditor::getDockManager()->addDock(new ProjectExplorerDock(this));

}

ProjectManager::~ProjectManager()
{
    QHashIterator<int, Project*> projectIterator(mProjects);
    while (projectIterator.hasNext()) {
        projectIterator.next();
        delete (projectIterator.value());
    }
}

void ProjectManager::checkDb()
{
    DbManager *dbManager = CodeEditor::getDbManager();
    if (!dbManager->getDb().tables().contains("project", Qt::CaseInsensitive)) {
        const QString sql = QString(
            "CREATE TABLE 'main'.'project' ("
            "'id' INTEGER PRIMARY KEY AUTOINCREMENT,"
            "'name' TEXT NOT NULL,"
            "'location' TEXT NOT NULL"
            ");"
        );
        dbManager->query().exec(sql);
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
    const QString sql = QString("SELECT id, name, location FROM project");
    QSqlQuery query = CodeEditor::getDbManager()->query();

    if (!query.exec(sql)) {
        qWarning() << "Can't load projects from db";
        return;
    }

    while (query.next()) {
        int id = query.record().value(0).toInt();
        QString name = query.record().value(1).toString();
        QString location = query.record().value(2).toString();

        Project* project = new Project(id, name, location);
        addProject(project);
    }

}

void ProjectManager::addProject(Project *project)
{
    mProjects[project->getId()] = project;
    mCTagsIndexer->addProject(project);
}

void ProjectManager::createNewProject(QString name, QString location)
{
    qDebug() << "createNewProject" << name << " " << location;

    const QString sql = QString("INSERT INTO project (name, location) VALUES (?, ?)");
    QSqlQuery query = CodeEditor::getDbManager()->query();
    query.prepare(sql);
    query.addBindValue(name);
    query.addBindValue(location);
    if (!query.exec()) {
        qWarning() << "ProjectManager::createNewProject(): Can't insert project in db";
        qWarning() << query.lastError().text();
        return;
    }

    int id = query.lastInsertId().toInt();
    Project* project = new Project(id, name, location);
    addProject(project);

    //Refresh the project tree
    Dock *dock = CodeEditor::getDockManager()->getDock("project_explorer");
    if (dock) {
        QWidget *widget = dock->getChildWidget();
        ProjectTreeView *projectTree = qobject_cast<ProjectTreeView *>(widget);
        projectTree->addProject(project);
    }
   // emit buildProject(project);
}


void ProjectManager::indexProjects()
{
    mCTagsIndexer->start();
   /* vector<Project*>::const_iterator projectIterator;
    for(projectIterator = projects.begin(); projectIterator != projects.end(); ++projectIterator) {
        Project* project = (*projectIterator);
        CodeEditor::getCTagsIndexer()->indexProject(project);
        if (!project->isBuild()) {
           // emit index(project);
        }
    }

    CodeEditor::getCTagsIndexer()->start();*/
}

void ProjectManager::showNewProjectDialog()
{
   NewProjectDialog *newProjectDialog = new NewProjectDialog();
   newProjectDialog->show();
}

}
