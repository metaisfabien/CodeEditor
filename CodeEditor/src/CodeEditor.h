#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include "Export.h"

#include <QObject>

namespace CE {

class SettingManager;
class ThemeManager;
class MainWindow;
class EditorManager;
class PluginManager;
class Workspace;
class DockManager;
class ActionManager;
class TabWidgetManager;

class CE_EXPORT CodeEditor : public QObject
{
    Q_OBJECT
public:
    static void init();
    static SettingManager* getSettingManager() { return mSettingManager; }
    static ThemeManager* getThemeManager() { return mThemeManager; }
    static MainWindow* getMainWindow() { return mMainWindow; }
    static EditorManager* getEditorManager() { return mEditorManager; }
    static PluginManager* getPluginManager() { return mPluginManager; }
    static Workspace* getWorkspace() { return mWorkspace; }
    static DockManager* getDockManager() { return mDockManager; }
    static ActionManager* getActionManager() { return mActionManager; }
    static TabWidgetManager *getTabWidgetManager() { return mTabWidgetManager; }

    static SettingManager *mSettingManager;
    static ThemeManager *mThemeManager;
    static MainWindow *mMainWindow;
    static EditorManager *mEditorManager;
    static PluginManager *mPluginManager;
    static Workspace *mWorkspace;
    static DockManager *mDockManager;
    static ActionManager *mActionManager;
    static TabWidgetManager *mTabWidgetManager;
};

}

#endif // CODEEDITOR_H
