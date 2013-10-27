#include "ProjectExplorerDock.h"
#include "ProjectTree/ProjectTreeView.h"
#include "ProjectManager.h"

#include "CodeEditor.h"

#include "Dock/Dock.h"

namespace CE {
namespace Project {

ProjectExplorerDock::ProjectExplorerDock(QString id, QString title, ProjectManager *projectManager) :
    Dock(id, title)
{
    mProjectManager = projectManager;
    mProjectTree = 0;
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
}

ProjectExplorerDock::~ProjectExplorerDock()
{
    if (mProjectTree) delete mProjectTree;
}

QWidget *ProjectExplorerDock::getChildWidget()
{
    mProjectTree = new ProjectTreeView(mProjectManager);
    return mProjectTree;
}

}
}

