#ifndef PROJECT_PLUGIN_H
#define PROJECT_PLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QHash>

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

    QHash <QString, Dock*> getDocks();

public slots:
    void showNewProjectDialog();
    void createNewProject(QString name,QString location);

private:
    QAction *mNewProjectAction;
    ProjectManager *mProjectManager;
    NewProjectDialog *mNewProjectDialog;
};
}
}

#endif // PROJECTPLUGIN_H
