#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>

namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();

    QString getName();
    QString getLocation();

private:
    void clean();

    Ui::NewProjectDialog *ui;

public slots:
    void browseLocation();
    void validate();
    void accept();
    void reject();
};

#endif // NEWPROJECTDIALOG_H
