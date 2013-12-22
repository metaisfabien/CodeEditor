#include "Setting/SettingsTreeItem.h"
#include "Setting/SettingsDialogSection.h"

namespace CE {
SettingsTreeItem::SettingsTreeItem(QString id, QTreeWidget *parent, SettingsDialogSection *section)
    : QTreeWidgetItem(parent)
{
    mId = id;
    mSection = section;
}

SettingsTreeItem::SettingsTreeItem(QString id, QTreeWidgetItem *parent, SettingsDialogSection *section)
    : QTreeWidgetItem(parent)
{
    mId = id;
    mSection = section;
}

void SettingsTreeItem::setText(QString text)
{
    QTreeWidgetItem::setText(0, text);
}

QString SettingsTreeItem::text()
{
    return QTreeWidgetItem::text(0);
}
}
