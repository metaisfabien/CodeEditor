#include "Setting/SettingsDialog.h"
#include "Setting/SettingsTreeItem.h"

namespace PHPEditor {
SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    SettingsTreeItem *generalTreeItem = new SettingsTreeItem("general", settingsTree);
    generalTreeItem->setText("General");

    SettingsTreeItem *editorsTreeItem = new SettingsTreeItem("editors", settingsTree);
    editorsTreeItem->setText("Editors");
   // addTreeItem("editors", "Editors");
}

SettingsDialog::~SettingsDialog()
{

}

}

