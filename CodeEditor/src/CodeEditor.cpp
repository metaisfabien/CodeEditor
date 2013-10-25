#include "CodeEditor.h"
#include "Setting/SettingManager.h"
#include "Theme/ThemeManager.h"
#include "MainWindow.h"
#include "Editor/EditorManager.h"
#include "Plugin/PluginManager.h"
#include "Dock/DockManager.h"
#include "Workspace/Workspace.h"
#include "Action/Manager.h"


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

    mMainWindow = new MainWindow(mActionManager);

    mPluginManager = new PluginManager;
    mDockManager = new DockManager(mPluginManager);
    mWorkspace = new Workspace(mMainWindow, mDockManager);

    mEditorManager = new EditorManager;

    mMainWindow->show();
}

}
