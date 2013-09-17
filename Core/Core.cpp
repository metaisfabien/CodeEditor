#include "Core.h"
#include "ConfigManager.h"
#include "ProjectManager.h"
#include "MainWindow.h"
#include "PluginManager.h"

#include <QDebug>

namespace PHPEditor {
ConfigManager* Core::configManager;
ProjectManager* Core::projectManager;
MainWindow* Core::mainWindow;
PluginManager* Core::pluginManager;

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
    projectManager = new ProjectManager;
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
 * @brief Core::getProjectManager
 *
 * Return the project manager instance
 *
 * @return ProjectManager*
 */
ProjectManager* Core::getProjectManager()
{
    return projectManager;
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
}
