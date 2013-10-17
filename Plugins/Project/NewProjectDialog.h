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
    NewProjectDialog(Plugin *phpPlugin, QWidget *parent = 0);
    ~NewProjectDialog();

    QString getName();
    QString getLocation();

private:
    void clean();

    Ui::NewProjectDialog *ui;
    Plugin *mPhpPlugin;

public slots:
    void openBrowseLocationDialog();
    void validate();
    void accept();
    void reject();
};
}
}

#endif // NEWPROJECTDIALOG_H
