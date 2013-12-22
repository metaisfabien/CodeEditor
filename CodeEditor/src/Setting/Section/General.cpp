#include "Setting/Section/General.h"
#include "Setting/SettingsDialog.h"

#include <QTreeWidget>
#include <QDebug>

namespace CE {

SettingGeneralSection::SettingGeneralSection(QString id, QTreeWidget *parent, SettingsDialog *settingsDialog)
    : SettingsDialogSection(id, parent, settingsDialog)
{
    setupUi(this);
}

SettingGeneralSection::SettingGeneralSection(QString id, SettingsDialogSection *parent, SettingsDialog *settingsDialog)
    : SettingsDialogSection(id, parent, settingsDialog)
{
    setupUi(this);
}

SettingGeneralSection::~SettingGeneralSection()
{

}
}


