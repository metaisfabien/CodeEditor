#ifndef CORE_H
#define CORE_H

#include "Export.h"

#include <QObject>

namespace PHPEditor {

class ConfigManager;
class MainWindow;
class PluginManager;

class PHPEDITOR_EXPORT Core : public QObject
{
    Q_OBJECT
public:
    static void init();
    static ConfigManager* getConfigManager();
    static MainWindow* getMainWindow();
    static PluginManager* getPluginManager();
    static void test();

    static ConfigManager *configManager;
    static MainWindow *mainWindow;
    static PluginManager *pluginManager;
};

}

#endif // PHPEDITOR_H
