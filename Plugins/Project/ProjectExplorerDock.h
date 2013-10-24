#ifndef PROJECT_PROJECTEXPLORERDOCK_H
#define PROJECT_PROJECTEXPLORERDOCK_H

#include "Dock/Dock.h"

#include <QObject>

namespace CE {
namespace Project {
class ProjectTreeView;
class ProjectManager;
class ProjectExplorerDock : public Dock
{
public:
    ProjectExplorerDock(QString id, QString title, ProjectManager *projectManager);
    ~ProjectExplorerDock();
    QWidget *getChildWidget();
private:
    ProjectTreeView *mProjectTree;
    ProjectManager *mProjectManager;
};
}
}

#endif // PROJECT_PROJECTEXPLORERDOCK_H
