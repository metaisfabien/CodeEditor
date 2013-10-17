#ifndef SETTINGSTREEITEM_H
#define SETTINGSTREEITEM_H

#include "Export.h"

#include <QObject>
#include <QTreeWidgetItem>

namespace CE {
class SettingsDialogSection;
class CE_EXPORT SettingsTreeItem :  public QObject, public QTreeWidgetItem
{
    Q_OBJECT
public:
    SettingsTreeItem(QString id, QTreeWidget *parent, SettingsDialogSection *section);
    SettingsTreeItem(QString id, QTreeWidgetItem *parent, SettingsDialogSection *section);

    void setText(QString text);
    QString text();

    QString getId() const { return mId; }
    void setWidget(QWidget *widget) { mWidget = widget; }

    SettingsDialogSection *getSection() const { return mSection; }

private:
    QString mId;
    QWidget *mWidget;
    SettingsDialogSection *mSection;
};
}
#endif // SETTINGSTREEITEM_H
