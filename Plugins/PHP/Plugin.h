#ifndef PHP_PLUGIN_H
#define PHP_PLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QHash>

#include "Plugin/PluginInterface.h"

namespace CE {
class SettingsDialog;
class Project;
namespace PHP {
class Plugin : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.PHPEditor.Default.PluginInterface" FILE "php.json")
    Q_INTERFACES(CE::PluginInterface)
    public:
        Plugin();
        ~Plugin();

        bool load();
        bool unLoad();

    public slots:
        void onCreateSettingDialog(SettingsDialog *SettingsDialog);
        void buildProject(Project* project);
};
}
}

#endif //PHP_PLUGIN_H
