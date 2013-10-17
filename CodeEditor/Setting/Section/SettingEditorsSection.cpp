#include "Setting/Section/SettingEditorsSection.h"
#include "Setting/SettingsDialog.h"
#include "Setting/SettingManager.h"

#include "CodeEditor.h"

#include <QTreeWidget>
#include <QSettings>
#include <QDebug>
#include <QObject>

namespace CE {

SettingEditorsSection::SettingEditorsSection(QString id, QTreeWidget *parent, SettingsDialog *settingsDialog)
    : SettingsDialogSection(id, parent, settingsDialog)
{
    setupUi(this);
}

SettingEditorsSection::SettingEditorsSection(QString id, SettingsDialogSection *parent, SettingsDialog *settingsDialog)
    : SettingsDialogSection(id, parent, settingsDialog)
{
    setupUi(this);
}

SettingEditorsSection::~SettingEditorsSection()
{

}

void SettingEditorsSection::setupUi(QWidget *settingEditorsSection)
{
    Ui::SettingEditorsSection::setupUi(settingEditorsSection);

    QSettings *settings = CodeEditor::getSettingManager()->getSettings();
    showLineNumber->setChecked(settings->value("editors/show_line_number").toBool());


    connect(mSettingsDialog, SIGNAL(updateSettings()), this , SLOT(updateSettings()));
}

void SettingEditorsSection::updateSettings()
{
    QSettings *settings = CodeEditor::getSettingManager()->getSettings();
    settings->setValue("editors/show_line_number", showLineNumber->isChecked());
}
}

