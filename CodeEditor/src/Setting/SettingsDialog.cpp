#include "Setting/SettingsDialog.h"
#include "Setting/SettingsTreeItem.h"
#include "Setting/Section/Editors.h"
#include "Setting/Section/FileAssociation.h"
#include "Setting/Section/General.h"
#include "Setting/Section/Theme.h"

#include "MainWindow.h"

#include <QDebug>
#include <QPushButton>

namespace CE {
SettingsDialog::SettingsDialog(MainWindow *parent) :
    QDialog(parent)
{
    setupUi(this);

    SettingGeneralSection *generalSection = new SettingGeneralSection("general", settingsTree, this);
    generalSection->setTitle("General");
    stackedWidget->addWidget(generalSection);

    SettingEditorsSection *editorSection = new SettingEditorsSection("editors", settingsTree, this);
    editorSection->setTitle("Editors");
    stackedWidget->addWidget(editorSection);

    SettingFileAssociationSection *fileAssociationSection = new SettingFileAssociationSection("file_assiciation", editorSection, this);
    fileAssociationSection->setTitle("File association");
    stackedWidget->addWidget(fileAssociationSection);

    SettingThemeSection *themeSection = new SettingThemeSection("theme", settingsTree, this);
    themeSection->setTitle("Theme");
    stackedWidget->addWidget(themeSection);

    //Set the current tree item
    if (!settingsTree->currentItem()) {
        settingsTree->setCurrentItem(generalSection->getTreeItem());
    }

    //show the related section and set the title
    SettingsTreeItem *settingsTreeItem = static_cast<SettingsTreeItem*>(settingsTree->currentItem());
    stackedWidget->setCurrentWidget(settingsTreeItem->getSection());
    title->setText(settingsTreeItem->text());

    connect(settingsTree, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this , SLOT(onTreeItemClicked(QTreeWidgetItem*, int)));

    //
    connect(buttonBox->button(QDialogButtonBox::Apply), SIGNAL(clicked()), this , SLOT(apply()));

    //buttonBox->button(QDialogButtonBox::Apply)->setEnabled(false);
}

SettingsDialog::~SettingsDialog()
{

}

SettingsTreeItem* SettingsDialog::getTreeItem(QString id)
{
    QTreeWidgetItemIterator it(settingsTree);

    while (*it) {
        SettingsTreeItem *item = static_cast<SettingsTreeItem*>(*it);
        if (item->getId() == id) {
            return item;
        }
        ++it;

    }

    return 0;
}

QTreeWidget* SettingsDialog::getTree()
{
    return settingsTree;
}

QStackedWidget* SettingsDialog::getStackedWidget()
{
    return stackedWidget;
}

/**
 * @brief SettingsDialog::onTreeItemClicked
 * @param item
 * @param column
 *
 * Callback when click on an item of the setting tree
 *
 * it change the current widget of the stacked widget and the title of the section
 */
void SettingsDialog::onTreeItemClicked(QTreeWidgetItem * item, int column)
{
    SettingsTreeItem *settingsTreeItem = static_cast<SettingsTreeItem*>(item);
    stackedWidget->setCurrentWidget(settingsTreeItem->getSection());
    title->setText(settingsTreeItem->text());
}

void SettingsDialog::accept()
{
    qDebug() << "accept";
    saveSettings();
}

void SettingsDialog::apply()
{
    qDebug() << "apply";
    saveSettings();
}

void SettingsDialog::saveSettings()
{
    emit updateSettings();
}
}
