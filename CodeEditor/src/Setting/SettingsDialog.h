#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include "ui_SettingsDialog.h"
#include "Export.h"

#include <QDialog>

namespace CE {
class SettingsTreeItem;
class MainWindow;
class CE_EXPORT SettingsDialog : public QDialog, public Ui::SettingsDialog
{
    Q_OBJECT

public:
    SettingsDialog(MainWindow *parent = 0);
    ~SettingsDialog();

    QTreeWidget* getTree();
    SettingsTreeItem* getTreeItem(QString id);
    QStackedWidget* getStackedWidget();



public slots:
    void onTreeItemClicked(QTreeWidgetItem * item, int column);
    void accept();
    void apply();

signals:
    void updateSettings();

private:
    void saveSettings();

};
}
#endif // SETTINGSDIALOG_H
