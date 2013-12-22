#ifndef SETTINGGENERALSECTION_H
#define SETTINGGENERALSECTION_H


#include "ui_SettingGeneralSection.h"
#include "Setting/SettingsDialogSection.h"

#include <QString>

QT_BEGIN_NAMESPACE
class QTreeWidget;
class QTreeWidgetItem;
QT_END_NAMESPACE

namespace CE {
class SettingsDialog;
class SettingGeneralSection : public SettingsDialogSection , public Ui::SettingGeneralSection
{
Q_OBJECT
public:
    SettingGeneralSection(QString id, QTreeWidget *parent, SettingsDialog *settingsDialog);
    SettingGeneralSection(QString id, SettingsDialogSection *parent, SettingsDialog *settingsDialog);

    ~SettingGeneralSection();
};
}

#endif // SETTINGGENERALSECTION_H
