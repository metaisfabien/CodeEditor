#ifndef CORE_H
#define CORE_H

#include "Export.h"

#include <QObject>

namespace PHPEditor {

class SettingManager;
class MainWindow;
class EditorManager;
class PluginManager;
class Workspace;

class PHPEDITOR_EXPORT Core : public QObject
{
    Q_OBJECT
public:
    static void init();
    static SettingManager* getSettingManager();
    static MainWindow* getMainWindow();
    static EditorManager* getEditorManager();
    static PluginManager* getPluginManager();
    static Workspace* getWorkspace();

    static SettingManager *mSettingManager;
    static MainWindow *mainWindow;
    static EditorManager *mEditorManager;
    static PluginManager *pluginManager;
    static Workspace *workspace;
};

}

#endif // PHPEDITOR_H
