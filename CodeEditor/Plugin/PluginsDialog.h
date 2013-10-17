#ifndef PLUGINSDIALOG_H
#define PLUGINSDIALOG_H

#include <QDialog>

namespace Ui {
class PluginsDialog;
}

namespace CE {
class PluginsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PluginsDialog(QWidget *parent = 0);
    ~PluginsDialog();

private:
    Ui::PluginsDialog *ui;
};
}
#endif // PLUGINSDIALOG_H
