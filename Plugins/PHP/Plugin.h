#ifndef PHPPLUGIN_H
#define PHPPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "Plugin/PluginInterface.h"

namespace PHPEditor {
class SettingsDialog;
namespace PHP {
class Plugin : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.PHPEditor.Default.PluginInterface" FILE "php.json")
    Q_INTERFACES(PHPEditor::PluginInterface)
    public:
        Plugin();
        ~Plugin();
        bool load();
        bool unLoad();

    public slots:
        void onCreateSettingDialog(SettingsDialog *SettingsDialog);
};
}
}

#endif // PHPPLUGIN_H
