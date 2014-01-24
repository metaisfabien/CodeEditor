#include "Dock/DockManager.h"
#include "Dock/Dock.h"
#include "Plugin/PluginManager.h"
#include "Plugin/PluginInterface.h"

namespace CE {
DockManager::DockManager()
{

}

void DockManager::addDock(Dock *dock)
{
    mDocks[dock->getId()] = dock;
}

Dock* DockManager::getDock(QString id)
{
    if (mDocks.contains(id)) {
        return mDocks[id];
    }

    return 0;
}

}
