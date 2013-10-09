#ifndef SETTINGSTREEITEM_H
#define SETTINGSTREEITEM_H

#include <QTreeWidgetItem>

namespace PHPEditor {
class SettingsTreeItem : public QTreeWidgetItem
{
public:
    SettingsTreeItem(QString id, QWidget *parent = 0);

    SettingsTreeItem(QString id, QTreeWidget *parent);
    SettingsTreeItem(QString id, QTreeWidgetItem *parent);

    void setText(QString text);

private:
    QString mId;
};
}
#endif // SETTINGSTREEITEM_H
