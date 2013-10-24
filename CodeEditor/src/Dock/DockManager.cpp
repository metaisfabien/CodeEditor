#include "Dock/DockManager.h"
#include "Plugin/PluginManager.h"
#include "Plugin/PluginInterface.h"

namespace CE {
DockManager::DockManager(PluginManager *pluginManager)
{
    mPluginManager = pluginManager;
    loadDocks();
}

void DockManager::loadDocks()
{
    QHashIterator<QString, PluginInterface*> pluginIterator(mPluginManager->getPlugins());
    while (pluginIterator.hasNext()) {
        pluginIterator.next();
        PluginInterface *plugin = pluginIterator.value();

        QHash<QString, Dock*> docks = plugin->getDocks();
        if (docks.count() > 0) {
            QHashIterator<QString, Dock*> dockIterator(docks);
            while (dockIterator.hasNext()) {
                dockIterator.next();
                mDocks[dockIterator.key()] = dockIterator.value();
            }
        }
    }
}

Dock* DockManager::getDock(QString id)
{
    if (mDocks.contains(id)) {
        return mDocks[id];
    }

    return 0;
}

}
