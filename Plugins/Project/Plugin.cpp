#include "Plugin.h"
#include "ProjectManager.h"
#include "ProjectTree/ProjectTreeView.h"

#include "NewProjectDialog.h"

#include "CodeEditor.h"
#include "MainWindow.h"
#include "MenuBar.h"

#include "Workspace/Dock.h"
#include "Workspace/Workspace.h"
#include "Workspace/Perspective.h"


#include <QDebug>
#include <QMenuBar>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QDockWidget>

namespace CE {
namespace Project {
Plugin::Plugin()
{
    mId = "project";

    mProjectManager = 0;
    mProjectTree = 0;
    mNewProjectAction = 0;
    mNewProjectDialog = 0;
}

Plugin::~Plugin()
{
    if (mNewProjectAction) delete mNewProjectAction;
    if (mProjectManager) delete mProjectManager;
    if (mNewProjectDialog) delete mNewProjectDialog;
    if (mProjectTree) delete mProjectTree;
}

bool Plugin::load()
{

    qDebug() << "Load project plugin";
    mProjectManager = new ProjectManager;

    mNewProjectAction = new QAction(QIcon(QApplication::applicationDirPath() +"/images/project.png"), tr("&Project"), this);
    mNewProjectAction->setStatusTip(tr("New project"));

    connect(mNewProjectAction, SIGNAL(triggered()), this, SLOT(showNewProjectDialog()));

    QMenu *newFileMenu = CodeEditor::getMainWindow()->menuBar()->menu("file/new");
    newFileMenu->addAction(mNewProjectAction);

    Dock* ProjectExplorerDock = CodeEditor::getWorkspace()->getCurrentPerspective()->getDock("project_explorer");
    if (ProjectExplorerDock) {
        //on crée le dock project manager
        QDockWidget *dockWidget = new QDockWidget(tr("Project explorer"), CodeEditor::getMainWindow());
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

        ProjectTreeView *mProjectTree = new ProjectTreeView(mProjectManager);
        dockWidget->setWidget(mProjectTree);
        CodeEditor::getMainWindow()->addDockWidget(Qt::RightDockWidgetArea, dockWidget);
    }

    return true;
}

bool Plugin::unLoad()
{
    return true;
}

/**
 * @brief PHPCore::showNewProjectDialog
 *
 * Show the dialog window to create a new project
 */
void Plugin::showNewProjectDialog()
{
    if (!mNewProjectDialog) {
        mNewProjectDialog = new NewProjectDialog(this);
    }
    mNewProjectDialog->show();
}

/**
 * @brief PHPCore::createNewProject
 *
 *
 */
void Plugin::createNewProject(QString name,QString location)
{
    mProjectManager->createNewProject(name, location);
    if (mProjectTree) {
        mProjectTree->addProject(name, location);
    }
}
}
}
