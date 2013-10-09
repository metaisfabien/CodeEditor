#include "Setting/SettingsTreeItem.h"

namespace PHPEditor {
SettingsTreeItem::SettingsTreeItem(QString id, QTreeWidget *parent)
    : QTreeWidgetItem(parent)
{
    mId = id;
}

SettingsTreeItem::SettingsTreeItem(QString id, QTreeWidgetItem *parent)
    : QTreeWidgetItem(parent)
{
    mId = id;
}

void SettingsTreeItem::setText(QString text)
{
    QTreeWidgetItem::setText(0, text);
}
}
