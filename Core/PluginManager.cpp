#include "PluginManager.h"
#include "ConfigManager.h"
#include "PluginInterface.h"
#include "Core.h"

#include <QApplication>
#include <QDebug>

namespace PHPEditor {
PluginManager::PluginManager()
{
    qDebug() << "PluginManager instanced";
    ConfigManager* configManager = Core::getConfigManager();
    configManager->loadConfig("plugins");
}

void PluginManager::loadPlugins()
{
    qDebug() << "Load plugins";
    //On récupère le path du dossier des plugins
    QDir pluginsDir = QDir(QApplication::applicationDirPath());
    pluginsDir.cd("plugins");

    //On parcour les contenu dans le dossier des plugins et on les charge
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        qDebug() << "Load plugin " << fileName;
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject* plugin = loader.instance();
        if (plugin) {
            loadPlugin(plugin);
        } else {
            qDebug() << "Can't' load plugin " << fileName;
        }
    }
}


void PluginManager::loadPlugin(QObject* plugin)
{
    PluginInterface* _plugin = qobject_cast<PluginInterface *>(plugin);
    if (_plugin) {
        _plugin->load();
        plugins.insert(std::make_pair<QString, PluginInterface*>(_plugin->getId(), _plugin));
    } else {
        qDebug() << "Can load plugin";
    }
}
}
