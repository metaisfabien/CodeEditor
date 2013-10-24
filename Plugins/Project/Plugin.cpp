#include "Plugin.h"
#include "ProjectManager.h"
#include "ProjectExplorerDock.h"

#include "NewProjectDialog.h"

#include "CodeEditor.h"
#include "MainWindow.h"
#include "MenuBar.h"

#include "Workspace/DockData.h"
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
    mNewProjectAction = 0;
    mNewProjectDialog = 0;
}

Plugin::~Plugin()
{
    if (mNewProjectAction) delete mNewProjectAction;
    if (mProjectManager) delete mProjectManager;
    if (mNewProjectDialog) delete mNewProjectDialog;
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

    return true;
}

bool Plugin::unLoad()
{
    return true;
}

QHash <QString, Dock*> Plugin::getDocks()
{
    QHash <QString, Dock*> docks;
    docks["project_explorer"] = new ProjectExplorerDock("project_explorer", tr("Project explorer"), mProjectManager);

    return docks;
}

/**
 * @brief PHPCore::showNewProjectDialog
 *
 * Show the dialog window to create a new project
 */
void Plugin::showNewProjectDialog()
{
    mNewProjectDialog = new NewProjectDialog(this);
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
   /* if (mProjectTree) {
        mProjectTree->addProject(name, location);
    }*/
}
}
}
