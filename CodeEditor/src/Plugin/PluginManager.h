#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <qglobal.h>
#include <QObject>
#include <QFile>
#include <QHash>

QT_BEGIN_NAMESPACE
class QAction;
class QObject;
class PluginInterface;
QT_END_NAMESPACE


using namespace std;

namespace CE {
class PluginInterface;
class PluginsDialog;
class PluginData;
class PluginManager : public QObject
{
    Q_OBJECT
public:
    PluginManager();
    ~PluginManager();

    QHash<QString, PluginData*> getPluginsData() const { return mPluginsData; }
    PluginData* getPluginData(QString id);

    QHash <QString, PluginInterface*> getPlugins() const { return mPlugins; }
    bool pluginDataExist(QString id);

public slots:
    void showPluginsDialog();

private:
    void loadPluginsData();
    void loadPluginData(QFile *pluginConfigFile, QString path);
    void loadPlugins();
    void loadPlugin(PluginData* pluginData);

    QHash<QString, PluginData*> mPluginsData;
    QHash<QString, PluginInterface*> mPlugins;
    PluginsDialog *mPluginsDialog;

    QAction *mPluginsAction;
};
}

#endif // PLUGINMANAGER_H
