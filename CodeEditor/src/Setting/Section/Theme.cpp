#include "Setting/Section/Theme.h"
#include "Setting/SettingsDialog.h"

#include "CodeEditor.h"
#include "Theme/Theme.h"
#include "Theme/ThemeManager.h"

#include <QTreeWidget>
#include <QDebug>


#include <map>

using namespace std;

namespace CE {

SettingThemeSection::SettingThemeSection(QString id, QTreeWidget *parent, SettingsDialog *settingsDialog)
    : SettingsDialogSection(id, parent, settingsDialog)
{
    setupUi(this);
}

SettingThemeSection::SettingThemeSection(QString id, SettingsDialogSection *parent, SettingsDialog *settingsDialog)
    : SettingsDialogSection(id, parent, settingsDialog)
{
    setupUi(this);
}

void SettingThemeSection::setupUi(QWidget *settingThemeSection)
{
    Ui::SettingThemeSection::setupUi(settingThemeSection);

    map<QString, Theme*> themes = CodeEditor::getThemeManager()->getThemes();
    map<QString, Theme*>::iterator themeIterator;
    for(themeIterator = themes.begin(); themeIterator != themes.end(); ++themeIterator) {
        themeComboBox->addItem((themeIterator->second)->getName(),(themeIterator->second)->getId());
    }

}

SettingThemeSection::~SettingThemeSection()
{

}
}


