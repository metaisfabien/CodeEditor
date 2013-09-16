#include "NewProjectDialog.h"
#include "ui_NewProjectDialog.h"

namespace PHPEditor {
NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}
}
