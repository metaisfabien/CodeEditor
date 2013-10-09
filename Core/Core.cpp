#include "Core.h"
#include "Setting/SettingManager.h"
#include "MainWindow.h"
#include "Editor/EditorManager.h"
#include "Plugin/PluginManager.h"
#include "Workspace/Workspace.h"


#include <QDebug>

namespace PHPEditor {
SettingManager* Core::mSettingManager;
MainWindow* Core::mainWindow;
PluginManager* Core::pluginManager;
Workspace* Core::workspace;
EditorManager* Core::mEditorManager;

/**
 * @brief PHPEditor::MonkeyCore::init
 *
 * Initialize all requier componement for PHPEditor
 * and show the main window
 */
void Core::init()
{
    qDebug() << "PHPEditor init";
    mSettingManager = new SettingManager;
    workspace = new Workspace;
    mainWindow = new MainWindow;
    mEditorManager = new EditorManager;
    pluginManager = new PluginManager;

    mainWindow->show();
}

/**
 * @brief PHPEditor::getConfigManager
 *
 * Return the project manager instance
 *
 * @return ConfigManager*
 */
SettingManager* Core::getSettingManager()
{
    return mSettingManager;
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

EditorManager* Core::getEditorManager()
{
    return mEditorManager;
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
