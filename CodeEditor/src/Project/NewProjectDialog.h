#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include "ui_NewProjectDialog.h"

#include <QDialog>

namespace Ui {
class NewProjectDialog;
}

namespace CE {

class NewProjectDialog : public QDialog, public Ui::NewProjectDialog
{
    Q_OBJECT

public:
    NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();

    QString getName();
    QString getLocation();

public slots:
    void openBrowseLocationDialog();
    void validate();
    void accept();
};

}

#endif // NEWPROJECTDIALOG_H
