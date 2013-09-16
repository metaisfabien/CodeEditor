#include "Core.h"
#include "ConfigManager.h"
#include "MainWindow.h"
#include "PluginManager.h"

#include <QDebug>

namespace PHPEditor {
ConfigManager* Core::configManager;
MainWindow* Core::mainWindow;
PluginManager* Core::pluginManager;

/**
 * @brief PHPEditor::MonkeyCore::init
 * Crée la fenètre principal
 */
void Core::init()
{
    qDebug() << "PHPEditor init";
    configManager = new ConfigManager;
    mainWindow = new MainWindow;
    pluginManager = new PluginManager;
    pluginManager->loadPlugins();
    mainWindow->show();
}

/**
 * @brief PHPEditor::getConfigManager
 * Renvoi l'instance du gestionnaire de configuration
 * @return
 */
ConfigManager* Core::getConfigManager()
{
    return configManager;
}

/**
 * @brief PHPEditor::getMainWindow
 * Renvoi l'instance de la fenètre principal
 * @return MainWindow*
 */
MainWindow* Core::getMainWindow()
{
    return mainWindow;
}

/**
 * @brief PHPEditor::getPluginManager
 * Renvoi l'instance du gestionnaire de plugin
 * @return PluginManager*
 */
PluginManager* Core::getPluginManager()
{
    return pluginManager;
}
}
