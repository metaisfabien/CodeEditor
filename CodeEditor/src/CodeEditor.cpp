#include "CodeEditor.h"
#include "Action/Manager.h"
#include "Setting/SettingManager.h"
#include "Theme/ThemeManager.h"
#include "MainWindow.h"
#include "Editor/EditorManager.h"
#include "Plugin/PluginManager.h"
#include "Project/ProjectManager.h"
#include "Dock/DockManager.h"
#include "Workspace/Workspace.h"
#include "CentralWidget/TabWidgetManager.h"
#include "Db/DbManager.h"


#include <QDebug>

namespace CE {
SettingManager* CodeEditor::mSettingManager;
ThemeManager* CodeEditor::mThemeManager;
MainWindow* CodeEditor::mMainWindow;
PluginManager* CodeEditor::mPluginManager;
ProjectManager* CodeEditor::mProjectManager;
Workspace* CodeEditor::mWorkspace;
EditorManager* CodeEditor::mEditorManager;
DockManager* CodeEditor::mDockManager;
ActionManager* CodeEditor::mActionManager;
TabWidgetManager* CodeEditor::mTabWidgetManager;
DbManager *CodeEditor::mDbManager;

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
    mDbManager = new DbManager;
    mThemeManager = new ThemeManager();
    mActionManager = new ActionManager();

    mTabWidgetManager = new TabWidgetManager();
    mMainWindow = new MainWindow(mActionManager, mTabWidgetManager);
    mThemeManager->setCurrentTheme("default");

    mEditorManager = new EditorManager;


    mDockManager = new DockManager();
    mProjectManager = new ProjectManager();
    mPluginManager = new PluginManager;

    mWorkspace = new Workspace(mMainWindow, mDockManager);

    mMainWindow->show();

    mProjectManager->indexProjects();
   // mProjectManager->buildProjects();
}

}
