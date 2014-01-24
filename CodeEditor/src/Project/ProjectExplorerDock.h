#ifndef PROJECT_PROJECTEXPLORERDOCK_H
#define PROJECT_PROJECTEXPLORERDOCK_H

#include "Dock/Dock.h"

#include <QObject>

namespace CE {
class ProjectTreeView;
class ProjectManager;
class ProjectExplorerDock : public Dock
{
public:
    ProjectExplorerDock(ProjectManager *projectManager);
    ~ProjectExplorerDock();
    QWidget *getChildWidget();

protected:
    ProjectTreeView *mProjectTree;
};
}

#endif // PROJECT_PROJECTEXPLORERDOCK_H
