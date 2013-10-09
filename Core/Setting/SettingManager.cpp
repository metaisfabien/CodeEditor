#include "Setting/SettingManager.h"
#include "Setting/SettingsDialog.h"

#include <QDir>
#include <QSettings>
#include <QApplication>

namespace PHPEditor {
SettingManager::SettingManager()
{
    mSettingsDialog = 0;

    QDir dataDir = QDir(QApplication::applicationDirPath());
    dataDir.cd("data");
    mSettings = new QSettings(dataDir.absoluteFilePath("settings.ini"), QSettings::IniFormat);
}

SettingManager::~SettingManager()
{
    delete mSettings;
}

void SettingManager::showSettingsDialog()
{
    if (!mSettingsDialog) {
        mSettingsDialog = new SettingsDialog();
        emit createSettingDialog(mSettingsDialog);
    }

    mSettingsDialog->show();
}
}
