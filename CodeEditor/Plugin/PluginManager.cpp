#include "Plugin/PluginManager.h"
#include "Plugin/PluginInterface.h"
#include "Plugin/PluginsDialog.h"
#include "Plugin/PluginData.h"

#include "Theme/ThemeManager.h"

#include "CodeEditor.h"
#include "MainWindow.h"
#include "MenuBar.h"

#include <QApplication>
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QObject>
#include <QPluginLoader>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDir>

namespace CE {
PluginManager::PluginManager()
{
    qDebug() << "PluginManager instanced";

    mPluginsDialog = 0;

    loadPluginsData();
    loadPlugins();

    mPluginsAction = new QAction(CodeEditor::getThemeManager()->getIcon("plugin"), tr("&Plugins"), this);
    mPluginsAction->setStatusTip(tr("Plugins"));
    QObject::connect(mPluginsAction, SIGNAL(triggered()), this, SLOT(showPluginsDialog()));

    QMenu *toolsMenu = CodeEditor::getMainWindow()->menuBar()->menu("tools");
    toolsMenu->addAction(mPluginsAction);
}

PluginManager::~PluginManager()
{
    map<QString, PluginInterface*>::iterator pluginIterator;
    for(pluginIterator = mPlugins.begin(); pluginIterator != mPlugins.end(); ++pluginIterator) {
        delete pluginIterator->second;
    }

    map<QString, PluginData*>::iterator pluginDataIterator;
    for(pluginDataIterator = mPluginsData.begin(); pluginDataIterator != mPluginsData.end(); ++pluginDataIterator) {
        delete pluginDataIterator->second;
    }

    if (mPluginsDialog) {
        delete mPluginsDialog;
    }
}

/**
 * @brief PluginManager::loadPluginsData
 *
 * Load all plugins data from plugin.json  +
 */
void PluginManager::loadPluginsData()
{
    //get the path of the plugins dir
    QDir pluginsDir = QDir(QApplication::applicationDirPath() + "/plugins");
    //pluginsDir.cd("plugins");
    qDebug() << "load plugins data from: " + pluginsDir.absolutePath();
    foreach (QString dirName, pluginsDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        //qDebug() << pluginsDir.absolutePath() + "/" + dirName + "/plugin.json";
        QFile *pluginConfigFile = new QFile(pluginsDir.absolutePath() + "/" + dirName + "/plugin.json");

        if (pluginConfigFile->exists()) {
            loadPluginData(pluginConfigFile, pluginsDir.absolutePath() + "/" + dirName);
        } else {
            qDebug() << "there is no plugin.json in the plugin folder "  + pluginsDir.absolutePath() + "/" + dirName;
        }

    }
}

/**
 * @brief loadPluginData
 * @param pluginConfigFile
 *
 * Create a PluginData instance from a plugin.json file
 * and add it to the PluginData map
 */
void PluginManager::loadPluginData(QFile *pluginConfigFile, QString pluginPath)
{
    pluginConfigFile->open(QIODevice::ReadOnly | QIODevice::Text);
    QString pluginConfigJson = pluginConfigFile->readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(pluginConfigJson.toUtf8());

    if (jsonDocument.isObject()) {
        QJsonObject pluginConfig = jsonDocument.object();
        if (pluginConfig["id"].toString() != "") {
            QString pluginId = pluginConfig["id"].toString();
            if (!pluginDataExist(pluginId)) {
                QString pluginName                = pluginConfig["name"].toString();
                QString pluginDescription         = pluginConfig["description"].toString();
                QString pluginVersion             = pluginConfig["version"].toString();
                QString pluginCodeEditorMinVersion = pluginConfig["CodeEditorMinVersion"].toString();
                QString fileName = pluginConfig["fileName"].toString();

                PluginData *pluginData = new PluginData(pluginId, pluginName);
                pluginData->setDescription(pluginDescription);
                pluginData->setVersion(pluginVersion);
                pluginData->setCodeEditorMinVerion(pluginCodeEditorMinVersion);
                pluginData->setPath(pluginPath);
                pluginData->setFileName(fileName);

                QJsonArray dependencies = pluginConfig["dependencies"].toArray();
                for(int i = 0; i < dependencies.count(); i++) {
                    pluginData->addDependency(dependencies[i].toString());
                }

                mPluginsData.insert(std::make_pair<QString, PluginData*>(pluginId, pluginData));
            } else {
                qDebug() << "Plugin " + pluginId + " already exist in the plugin data map";
            }
        } else {
             qDebug() << "Plugin config file " + pluginConfigFile->fileName() + " have no id";
        }
    } else {
        qDebug() << "Plugin config file " + pluginConfigFile->fileName() + " is not valid";
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

/**
 * @brief PluginManager::pluginDataExist
 *
 * Check if a plugin data exist in the pluginData map
 *
 * @param id
 * @return
 */
bool PluginManager::pluginDataExist(QString id)
{
    if (getPluginData(id)) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief PluginManager::loadPluginsConfig
 *
 * Load the plugins config file and set the config
 * on the PluginData objects
 */
void PluginManager::loadPlugins()
{
    QDir configDir = QDir(QApplication::applicationDirPath());
    configDir.cd("data");

    QFile *pluginsConfigFile = new QFile(configDir.absoluteFilePath("plugins.json"));

    if (pluginsConfigFile->exists()) {
        pluginsConfigFile->open(QIODevice::ReadOnly | QIODevice::Text);
        QString pluginsConfigJson = pluginsConfigFile->readAll();
        QJsonDocument jsonDocument = QJsonDocument::fromJson(pluginsConfigJson.toUtf8());
        QJsonArray plugins = jsonDocument.array();

        for(int i = 0; i < plugins.count(); i++) {
            QJsonObject plugin = plugins[i].toObject();
            if (plugin["id"].toString() != "") {
                PluginData *pluginData = getPluginData(plugin["id"].toString());
                if (pluginData && plugin["is_enabled"].toBool()) {
                    pluginData->setIsEnable(true);
                    loadPlugin(pluginData);
                    qDebug() << "Enable plugin " + pluginData->getId();
                }
            }
        }
    } else {
        qDebug() << "plugins config file " + pluginsConfigFile->fileName() + " not exist";
    }
}

/**
 * @brief PluginManager::loadPlugin
 * @param plugin
 *
 * Load a plugin and insert it in the plugins map
 */
void PluginManager::loadPlugin(PluginData *pluginData)
{
    QDir pluginDir;

    #ifdef Q_OS_LINUX
    QString pluginPath = pluginData->getPath() + "/lib" + pluginData->getFileName() +".so";
    #endif

    #ifdef Q_OS_WIN32
    QString pluginPath = pluginData->getPath() + "/" + pluginData->getFileName() +".dll";
    #endif

    QPluginLoader loader(pluginDir.absoluteFilePath(pluginPath));
    QObject* plugin = loader.instance();
    if (plugin) {
        PluginInterface* _plugin = qobject_cast<PluginInterface *>(plugin);
        if (_plugin) {
            _plugin->load();
            mPlugins.insert(std::make_pair<QString, PluginInterface*>(_plugin->getId(), _plugin));
        } else {
            qDebug() << "Plugin " + pluginData->getPath() + "/" + pluginData->getFileName() + " is'nt valid";
        }
    } else {
        qDebug() << "Can't' load plugin " + pluginPath;
    }

}

/**
 * @brief PluginManager::showPluginsDialog
 * Show the plugin dialog window
 */
void PluginManager::showPluginsDialog()
{
    if (!mPluginsDialog) {
        mPluginsDialog = new PluginsDialog();
    }
    mPluginsDialog->show();
}
}
