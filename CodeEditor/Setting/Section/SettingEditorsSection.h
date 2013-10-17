#ifndef SETTINGEDITORSSECTION_H
#define SETTINGEDITORSSECTION_H

#include "ui_SettingEditorsSection.h"
#include "Setting/SettingsDialogSection.h"

#include <QString>

QT_BEGIN_NAMESPACE
class QTreeWidget;
class QTreeWidgetItem;
QT_END_NAMESPACE

namespace CE {
class SettingsDialog;
class SettingEditorsSection : public SettingsDialogSection , public Ui::SettingEditorsSection
{
Q_OBJECT
public:    
    SettingEditorsSection(QString id, QTreeWidget *parent, SettingsDialog *settingsDialog);
    SettingEditorsSection(QString id, SettingsDialogSection *parent, SettingsDialog *settingsDialog);

    ~SettingEditorsSection();


    void setupUi(QWidget *settingEditorsSection);

public slots:
    void updateSettings();
};
}

#endif // SETTINGEDITORSSECTION_H
