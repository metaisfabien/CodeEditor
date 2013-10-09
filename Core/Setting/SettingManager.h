#ifndef SETTINGMANAGER_H
#define SETTINGMANAGER_H

#include <QObject>
QT_BEGIN_NAMESPACE
class QSettings;
QT_END_NAMESPACE

namespace PHPEditor {
class SettingsDialog;
class SettingManager : public QObject
{
    Q_OBJECT
public:
    SettingManager();
    ~SettingManager();



public slots:
    void showSettingsDialog();

signals:
    void createSettingDialog(SettingsDialog *settingsDialog);

private:
    QSettings *mSettings;
    SettingsDialog *mSettingsDialog;

};
}

#endif // PLUGINMANAGER_H
