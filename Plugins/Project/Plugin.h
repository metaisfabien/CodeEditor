#ifndef PROJECTPLUGIN_H
#define PROJECTPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "Plugin/PluginInterface.h"

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

namespace CE {
namespace Project {

class ProjectManager;
class NewProjectDialog;
class ProjectTreeView;

class Plugin : public QObject, PluginInterface
{
Q_OBJECT
Q_PLUGIN_METADATA(IID "org.PHPEditor.Default.PluginInterface" FILE "project.json")
Q_INTERFACES(CE::PluginInterface)
public:
    Plugin();
    ~Plugin();
    bool load();
    bool unLoad();

public slots:
    void showNewProjectDialog();
    void createNewProject(QString name,QString location);

private:
    QAction *mNewProjectAction;
    ProjectManager *mProjectManager;
    NewProjectDialog *mNewProjectDialog;
    ProjectTreeView *mProjectTree;
};
}
}

#endif // PROJECTPLUGIN_H
