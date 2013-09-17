#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>

namespace Ui {
class NewProjectDialog;
}

namespace PHPEditor {
class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();

private:
    Ui::NewProjectDialog *ui;

public slots:
    void browseLocation();
    void validate();
    void accept();
};
}

#endif // NEWPROJECTDIALOG_H
