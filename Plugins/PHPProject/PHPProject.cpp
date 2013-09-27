#include "PHPProject.h"
#include "ProjectManager.h"
#include "ProjectTreeModel.h"
#include "NewProjectDialog.h"

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
#include <QTreeView>
#include <QHeaderView>

using namespace PHPEditor;

PHPProject::PHPProject()
{
    id = "php_project";

    mProjectManager = 0;
    mNewProjectAction = 0;
    mNewProjectDialog = 0;
}

PHPProject::~PHPProject()
{
    if (mNewProjectAction) delete mNewProjectAction;
    if (mProjectManager) delete mProjectManager;
    if (mNewProjectDialog) delete mNewProjectDialog;
}

bool PHPProject::load()
{
    mProjectManager = new ProjectManager;

    mNewProjectAction = new QAction(QIcon(QApplication::applicationDirPath() +"/images/php_project.png"), tr("&PHP project"), this);
    mNewProjectAction->setStatusTip(tr("project"));

    connect(mNewProjectAction, SIGNAL(triggered()), this, SLOT(showNewProjectDialog()));

    Core::getMainWindow()->getNewMenu()->addAction(mNewProjectAction);

    Dock* ProjectExplorerDock = Core::getWorkspace()->getCurrentPerspective()->getDock("project_explorer");
    if (ProjectExplorerDock) {
        //on crée le dock project manager
        QDockWidget *dockWidget = new QDockWidget(tr("Project explorer"), Core::getMainWindow());
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

        mProjectTreeModel = new ProjectTreeModel(mProjectManager);
        QTreeView *tree = new QTreeView;
        //hide the tree header
        tree->header()->close();
        tree->setModel(mProjectTreeModel);
        tree->setStyleSheet(QString("QTreeView::branch { border-image: none; }"));

        dockWidget->setWidget(tree);
        Core::getMainWindow()->addDockWidget(Qt::RightDockWidgetArea, dockWidget);
    }

    return true;
}

bool PHPProject::unLoad()
{
    return true;
}

/**
 * @brief PHPProject::showNewProjectDialog
 *
 * Show the dialog window to create a new project
 */
void PHPProject::showNewProjectDialog()
{
    if (!mNewProjectDialog) {
        mNewProjectDialog = new NewProjectDialog(this);
    }
    mNewProjectDialog->show();
}

/**
 * @brief PHPProject::createNewProject
 *
 *
 */
void PHPProject::createNewProject(QString name,QString location)
{
    mProjectManager->createNewProject(name, location);
    mProjectTreeModel->addProject(name, location);
}
