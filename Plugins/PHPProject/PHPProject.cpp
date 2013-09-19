#include "PHPProject.h"
#include "ProjectManager.h"
#include "Project.h"
#include "ProjectTreeModel.h"

#include "Core.h"
#include "MainWindow.h"
#include "Workspace/Dock.h"
#include "Workspace/Workspace.h"
#include "Workspace/Perspective.h"


#include <QDebug>
#include <QMenuBar>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QDockWidget>
#include <QTreeWidget>

#include <QFileSystemModel>
#include <QVBoxLayout>
#include <QDirModel>
#include <QTreeView>
#include <QHeaderView>

using namespace PHPEditor;

PHPProject::PHPProject()
{
    id = "php_project";

    projectManager = 0;
    newProjectAction = 0;
}

PHPProject::~PHPProject()
{
    if (newProjectAction) delete newProjectAction;
    if (projectManager) delete projectManager;

}

bool PHPProject::load()
{
    projectManager = new ProjectManager;

    newProjectAction = new QAction(QIcon(QApplication::applicationDirPath() +"/images/php_project.png"), tr("&PHP project"), this);
    newProjectAction->setStatusTip(tr("project"));

    connect(newProjectAction, SIGNAL(triggered()), projectManager, SLOT(showNewProjectDialog()));

    Core::getMainWindow()->getNewMenu()->addAction(newProjectAction);

    Dock* ProjectExplorerDock = Core::getWorkspace()->getCurrentPerspective()->getDock("project_explorer");
    if (ProjectExplorerDock) {
        //on crée le dock project manager
        QDockWidget *dockWidget = new QDockWidget(tr("Project explorer"), Core::getMainWindow());
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

        vector<Project*> projects = projectManager->getProjects();

        QWidget *container = new QWidget(dockWidget);
        QVBoxLayout *layout = new QVBoxLayout(container);
        vector<Project*>::const_iterator projectIterator;
        for(projectIterator = projects.begin(); projectIterator != projects.end(); ++projectIterator) {
            qDebug() << "Add project " << (*projectIterator)->getName() << (*projectIterator)->getLocation();
            ProjectTreeModel *model = new ProjectTreeModel((*projectIterator)->getName(), (*projectIterator)->getLocation());

           // model->setRootPath((*projectIterator)->getLocation());//;
            QTreeView *tree = new QTreeView;
            tree->header()->close();
            tree->setModel(model);
           // tree->setRootIndex(model->index((*projectIterator)->getLocation()));

            layout->addWidget(tree);
        }

        dockWidget->setWidget(container);
        Core::getMainWindow()->addDockWidget(Qt::RightDockWidgetArea, dockWidget);
    }

    return true;
}

bool PHPProject::unLoad()
{
    return true;
}

