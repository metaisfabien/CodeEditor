#include "Core.h"
#include "ConfigManager.h"
#include "MainWindow.h"
#include "Plugin/PluginManager.h"
#include "Workspace/Workspace.h"


#include <QDebug>

namespace PHPEditor {
ConfigManager* Core::configManager;
MainWindow* Core::mainWindow;
PluginManager* Core::pluginManager;
Workspace* Core::workspace;

/**
 * @brief PHPEditor::MonkeyCore::init
 *
 * Initialize all requier componement for PHPEditor
 * and show the main window
 */
void Core::init()
{
    qDebug() << "PHPEditor init";
    configManager = new ConfigManager;
    workspace = new Workspace;
    mainWindow = new MainWindow;
    pluginManager = new PluginManager;
    pluginManager->loadPlugins();

    mainWindow->show();
}

/**
 * @brief PHPEditor::getConfigManager
 *
 * Return the project manager instance
 *
 * @return ConfigManager*
 */
ConfigManager* Core::getConfigManager()
{
    return configManager;
}

/**
 * @brief PHPEditor::getMainWindow
 *
 * Return the main window instance
 *
 * @return MainWindow*
 */
MainWindow* Core::getMainWindow()
{
    return mainWindow;
}

/**
 * @brief PHPEditor::getPluginManager
 *
 * Return the plugin manager instance
 *
 * @return PluginManager*
 */
PluginManager* Core::getPluginManager()
{
    return pluginManager;
}

/**
 * @brief PHPEditor::getWorkspace
 *
 * Return the workspace instance
 *
 * @return Workspace*
 */
Workspace* Core::getWorkspace()
{
    return workspace;
}
}
