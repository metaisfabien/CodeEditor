#include "Plugin/PluginManager.h"
#include "Plugin/PluginInterface.h"
#include "Plugin/PluginsDialog.h"

#include "ConfigManager.h"
#include "Core.h"
#include "MainWindow.h"
#include <QApplication>
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QObject>
#include <QPluginLoader>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

namespace PHPEditor {
PluginManager::PluginManager()
{
    qDebug() << "PluginManager instanced";
    loadPluginsData();

    createActions();
}

/**
 * @brief PluginManager::loadPluginsData
 *
 * Load all plugins data from plugin.json files
 */
void PluginManager::loadPluginsData()
{
    qDebug() << "load plugins data";
    //get the path of the plugins dir
    QDir pluginsDir = QDir(QApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    foreach (QDir pluginDir, pluginsDir.entryList(QDir::Dirs)) {
        qDebug() << pluginDir.absoluteFilePath("plugin.json");
        /*QFile pluginConfigFile(pluginDir.absoluteFilePath("/plugin.json"));
        if (pluginConfigFile.exists()) {
            loadPluginData(pluginConfigFile);
        }*/
    }
}

/**
 * @brief loadPluginData
 * @param pluginConfigFile
 *
 * Create a PluginData instance from a plugin.json file
 * and add it to the PluginData map
 */
void PluginManager::loadPluginData(QFile pluginConfigFile)
{
    pluginConfigFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QString pluginConfigJson = pluginConfigFile.readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(pluginConfigJson.toUtf8());
    QJsonObject pluginConfig = jsonDocument.object();
    if (pluginConfig["id"].toString() != "") {
        QString pluginId = pluginConfig["id"].toString();
        if (!pluginDataExist(pluginId)) {

        } else {
            qDebug() << "Plugin " << pluginId << " already exist in the plugin data map";
        }
    }
}

/**
 * @brief PluginManager::getPluginData
 *
 * Search a PluginData in the PluginData map by his id and return it
 *
 * @param Qstring id id of the PluginData to find
 *
 * @return PluginData*
 */
PluginData* PluginManager::getPluginData(QString id)
{
    map<QString, PluginData*>::iterator pluginDataIterator;
    pluginDataIterator = mPluginsData.find(id);

    if (pluginDataIterator != mPluginsData.end()) {
        return pluginDataIterator->second;
    }
    return 0;
}

bool PluginManager::pluginDataExist(QString id)
{
    if (getPluginData(id)) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief PluginManager::createAction
 * Create menu actions for plugins
 */
void PluginManager::createActions()
{
    mPluginsAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/setting.png"), tr("&Plugins"), Core::getMainWindow()->getOptionsMenu());
    mPluginsAction->setStatusTip(tr("Plugins"));
    connect(mPluginsAction, SIGNAL(triggered()), this, SLOT(showPluginsDialog()));

    Core::getMainWindow()->getOptionsMenu()->addAction(mPluginsAction);

}

void PluginManager::loadPlugins()
{
    qDebug() << "Load plugins";
    //get the path of the plugins dir
    QDir pluginsDir = QDir(QApplication::applicationDirPath());
    pluginsDir.cd("plugins");

    //read the plugins dir and load the plugins
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

/**
 * @brief PluginManager::loadPlugin
 * @param plugin
 *
 * Load a plugin and insert it in the plugins map
 */
void PluginManager::loadPlugin(QObject* plugin)
{
    PluginInterface* _plugin = qobject_cast<PluginInterface *>(plugin);
    if (_plugin) {
        _plugin->load();
        mPlugins.insert(std::make_pair<QString, PluginInterface*>(_plugin->getId(), _plugin));
    } else {
        qDebug() << "Can load plugin";
    }
}

void PluginManager::showPluginsDialog()
{
    if (!mPluginsDialog) {
        mPluginsDialog = new PluginsDialog();
    }
    mPluginsDialog->show();
}
}
