#ifndef DOCK_DOCKMANAGER_H
#define DOCK_DOCKMANAGER_H

#include <QHash>

namespace CE {
class Dock;
class PluginManager;
class DockManager
{
public:
    DockManager(PluginManager *pluginManager);
    void loadDocks();
    Dock *getDock(QString id);

private:
    PluginManager *mPluginManager;
    QHash <QString, Dock*> mDocks;
};
}
#endif // DOCK_DOCKMANAGER_H
