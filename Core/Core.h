#ifndef CORE_H
#define CORE_H

#include "Export.h"

#include <QObject>

namespace PHPEditor {

class ConfigManager;
class MainWindow;
class PluginManager;
class Workspace;

class PHPEDITOR_EXPORT Core : public QObject
{
    Q_OBJECT
public:
    static void init();
    static ConfigManager* getConfigManager();
    static MainWindow* getMainWindow();
    static PluginManager* getPluginManager();
    static Workspace* getWorkspace();

    static ConfigManager *configManager;
    static MainWindow *mainWindow;
    static PluginManager *pluginManager;
    static Workspace *workspace;
};

}

#endif // PHPEDITOR_H
