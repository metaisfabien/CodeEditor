#ifndef DOCK_DOCKMANAGER_H
#define DOCK_DOCKMANAGER_H

#include <QHash>

namespace CE {
class Dock;
class DockManager
{
public:
    DockManager();
    Dock *getDock(QString id);
    void addDock(Dock *dock);

private:

    QHash <QString, Dock*> mDocks;
};
}
#endif // DOCK_DOCKMANAGER_H
