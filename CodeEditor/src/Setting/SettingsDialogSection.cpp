#include "Setting/SettingsDialogSection.h"
#include "Setting/SettingsDialog.h"
#include "Setting/SettingsTreeItem.h"

#include <QDebug>

namespace CE {

/**
 * @brief SettingsDialogSection::SettingsDialogSection
 * @param id
 * @param parent
 *
 * Create the tree item
 */
SettingsDialogSection::SettingsDialogSection(QString id, QTreeWidget *parent, SettingsDialog *settingsDialog)
{
    mId = id;
    mTreeItem = new SettingsTreeItem(id, parent, this);
    mSettingsDialog = settingsDialog;
}

/**
 * @brief SettingsDialogSection::SettingsDialogSection
 * @param id
 * @param parent
 *
 * Create the tree item
 */
SettingsDialogSection::SettingsDialogSection(QString id, SettingsDialogSection *parent, SettingsDialog *settingsDialog)
{
    mId = id;
    mTreeItem = new SettingsTreeItem(id, parent->getTreeItem(), this);
    mSettingsDialog = settingsDialog;
}

SettingsDialogSection::~SettingsDialogSection()
{
    //delete mTreeItem;
}

/**
 * @brief SettingsDialogSection::setTitle
 *
 * Set the tilte of the section and the title of the tree item
 *
 * @param title
 */
void SettingsDialogSection::setTitle(QString title)
{
    mTitle = title;
    mTreeItem->setText(title);
}
}
