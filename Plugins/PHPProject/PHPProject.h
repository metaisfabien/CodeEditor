#ifndef PHPPROJECT_H
#define PHPPROJECT_H

#include <QObject>
#include <QtPlugin>

#include "PluginInterface.h"

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

using namespace PHPEditor;

class ProjectManager;
class PHPProject : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.PHPEditor.Default.PluginInterface" FILE "php_project.json")
    Q_INTERFACES(PHPEditor::PluginInterface)
    public:
        PHPProject();
        ~PHPProject();
        bool load();
        bool unLoad();

    private:
        QAction *newProjectAction;
        ProjectManager *projectManager;
        QString id;


};

#endif // TESTPLUGIN_H
