#ifndef SETTINGSDIALOGSECTION_H
#define SETTINGSDIALOGSECTION_H

#include <QString>
#include <QWidget>
#include <QTreeWidgetItem>
#include <QTreeWidget>

namespace CE {
class SettingsTreeItem;
class SettingsDialog;
class SettingsDialogSection : public QWidget
{
public:
    SettingsDialogSection(QString id, QTreeWidget *parent, SettingsDialog *settingsDialog);
    SettingsDialogSection(QString id, SettingsDialogSection *parent, SettingsDialog *settingsDialog);

    ~SettingsDialogSection();

    void setTitle(QString title);
    QString getTitle() const { return mTitle; }

    SettingsTreeItem *getTreeItem() const { return mTreeItem; }

protected:
    SettingsDialog *mSettingsDialog;

private:
    QString mTitle;
    QString mId;
    SettingsTreeItem *mTreeItem;
};
}

#endif // SETTINGSDIALOGSECTION_H
