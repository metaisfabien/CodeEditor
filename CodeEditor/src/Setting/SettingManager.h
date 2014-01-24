#ifndef SETTINGMANAGER_H
#define SETTINGMANAGER_H

#include <QObject>

QT_BEGIN_NAMESPACE
class QSettings;
QT_END_NAMESPACE

namespace CE {
class SettingsDialog;
class SettingManager : public QObject
{
    Q_OBJECT
public:
    SettingManager();
    ~SettingManager();
    QSettings *getSettings() const { return mSettings; }

public slots:
    void showSettingsDialog();
    void onUpdateSettings();

signals:
    void createSettingDialog(SettingsDialog *settingsDialog);
    void updateSettings();

private:
    QSettings *mSettings;
    SettingsDialog *mSettingsDialog;

};
}

#endif // PLUGINMANAGER_H
