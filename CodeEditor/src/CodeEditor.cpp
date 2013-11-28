#include "CodeEditor.h"
#include "Setting/SettingManager.h"
#include "Theme/ThemeManager.h"
#include "MainWindow.h"
#include "Editor/EditorManager.h"
#include "Plugin/PluginManager.h"
#include "Dock/DockManager.h"
#include "Workspace/Workspace.h"
#include "Action/Manager.h"
#include "CentralWidget/TabWidgetManager.h"


#include <QDebug>

namespace CE {
SettingManager* CodeEditor::mSettingManager;
ThemeManager* CodeEditor::mThemeManager;
MainWindow* CodeEditor::mMainWindow;
PluginManager* CodeEditor::mPluginManager;
Workspace* CodeEditor::mWorkspace;
EditorManager* CodeEditor::mEditorManager;
DockManager* CodeEditor::mDockManager;
ActionManager* CodeEditor::mActionManager;
TabWidgetManager* CodeEditor::mTabWidgetManager;

/**
 * @brief CodeEditor::MonkeyCodeEditor::init
 *
 * Initialize all requier componement for CodeEditor
 * and show the main window
 */
void CodeEditor::init()
{
    qDebug() << "CodeEditor init";
    mSettingManager = new SettingManager;
    mThemeManager = new ThemeManager();
    mActionManager = new ActionManager();

    mTabWidgetManager = new TabWidgetManager();
    mMainWindow = new MainWindow(mActionManager, mTabWidgetManager);

    mEditorManager = new EditorManager;

    mPluginManager = new PluginManager;
    mDockManager = new DockManager(mPluginManager);
    mWorkspace = new Workspace(mMainWindow, mDockManager);



    mMainWindow->show();
}

}
