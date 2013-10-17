#ifndef SETTINGTHEMESECTION_H
#define SETTINGTHEMESECTION_H

#include "ui_SettingThemeSection.h"
#include "Setting/SettingsDialogSection.h"

#include <QString>

QT_BEGIN_NAMESPACE
class QTreeWidget;
class QTreeWidgetItem;
QT_END_NAMESPACE

namespace CE {
class SettingsDialog;
class SettingThemeSection : public SettingsDialogSection , public Ui::SettingThemeSection
{
public:
    SettingThemeSection(QString id, QTreeWidget *parent, SettingsDialog *settingsDialog);
    SettingThemeSection(QString id, SettingsDialogSection *parent, SettingsDialog *settingsDialog);

    ~SettingThemeSection();

    void setupUi(QWidget *settingThemeSection);
};
}

#endif // SETTINGTHEMESECTION_H
