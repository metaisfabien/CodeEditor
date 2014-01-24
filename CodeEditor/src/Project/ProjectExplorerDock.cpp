#include "Project/ProjectExplorerDock.h"
#include "Project/Tree/View.h"
#include "Project/ProjectManager.h"

#include "CodeEditor.h"

#include "Dock/Dock.h"

namespace CE {
ProjectExplorerDock::ProjectExplorerDock(ProjectManager *projectManager) :
    Dock("project_explorer", "Project explorer")
{
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    mProjectTree = new ProjectTreeView(projectManager);
}

ProjectExplorerDock::~ProjectExplorerDock()
{
    if (mProjectTree) delete mProjectTree;
}

QWidget *ProjectExplorerDock::getChildWidget()
{
    return mProjectTree;
}
}

