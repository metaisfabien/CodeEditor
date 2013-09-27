#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <map>

#include <qglobal.h>
#include <QObject>
#include <QFile>

QT_BEGIN_NAMESPACE
class QAction;
class QObject;
class PluginInterface;
QT_END_NAMESPACE


using namespace std;

namespace PHPEditor {
class PluginInterface;
class PluginsDialog;
class PluginData;
class PluginManager : public QObject
{
    Q_OBJECT
public:
    PluginManager();
    void loadPlugins();
    void loadPlugin(QObject* plugin);

    map<QString, PluginData*> getPluginsData() const { return mPluginsData; }
    PluginData* getPluginData(QString id);

    bool pluginDataExist(QString id);
    void createActions();

public slots:
    void showPluginsDialog();

private:
    void loadPluginsData();
    void loadPluginData(QFile pluginConfigFile);

    map<QString, PluginData*> mPluginsData;
    map<QString, PluginInterface*> mPlugins;
    QAction *mPluginsAction;
    PluginsDialog *mPluginsDialog;
};
}

#endif // PLUGINMANAGER_H
