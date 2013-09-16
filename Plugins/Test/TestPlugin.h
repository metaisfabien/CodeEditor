#ifndef TESTPLUGIN_H
#define TESTPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QAction>
#include <QCoreApplication>

#include "PluginInterface.h"

using namespace PHPEditor;

class TestPlugin : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.PHPEditor.Default.PluginInterface" FILE "test_plugin.json")
    Q_INTERFACES(PHPEditor::PluginInterface)
    public:
        TestPlugin();
        ~TestPlugin() {}
        bool load();
        bool unLoad();

        QString getId();
        bool getIsLoaded(){ return isLoaded; }
        QString getVersion(){ return version; }

        QString id;

};

#endif // TESTPLUGIN_H
