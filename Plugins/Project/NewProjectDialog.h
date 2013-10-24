#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include "ui_NewProjectDialog.h"

#include <QDialog>

namespace Ui {
class NewProjectDialog;
}

namespace CE {
namespace Project {
class Plugin;

class NewProjectDialog : public QDialog, public Ui::NewProjectDialog
{
    Q_OBJECT

public:
    NewProjectDialog(Plugin *plugin, QWidget *parent = 0);
    ~NewProjectDialog();

    QString getName();
    QString getLocation();

private:
    Plugin *mPlugin;

public slots:
    void openBrowseLocationDialog();
    void validate();
    void accept();
};
}
}

#endif // NEWPROJECTDIALOG_H
