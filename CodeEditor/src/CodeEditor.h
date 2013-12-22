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

class CE_EXPORT CodeEditor : public QObject
{
    Q_OBJECT
public:
    static void init();
    static SettingManager* getSettingManager();
    static ThemeManager* getThemeManager();
    static MainWindow* getMainWindow();
    static EditorManager* getEditorManager();
    static PluginManager* getPluginManager();
    static Workspace* getWorkspace();

    static SettingManager *mSettingManager;
    static ThemeManager *mThemeManager;
    static MainWindow *mMainWindow;
    static EditorManager *mEditorManager;
    static PluginManager *mPluginManager;
    static Workspace *mWorkspace;
};

}

#endif // CODEEDITOR_H
