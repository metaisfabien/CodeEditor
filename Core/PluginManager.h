#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <map>

#include <QObject>
#include <QPluginLoader>

namespace PHPEditor {
class PluginInterface;
class PluginManager
{
public:
    PluginManager();
    void loadPlugins();
    void loadPlugin(QObject* plugin);

private:
    std::map<QString, PluginInterface*> plugins;
};
}

#endif // PLUGINMANAGER_H
