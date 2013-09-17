#include "NewProjectDialog.h"
#include "ui_NewProjectDialog.h"
#include "Core.h"
#include "ProjectManager.h"

#include <QFileDialog>
#include <QDebug>


namespace PHPEditor {
NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    connect(ui->projectName, SIGNAL(textChanged(const QString&)), this, SLOT(validate()));
    connect(ui->location, SIGNAL(textChanged(const QString&)), this, SLOT(validate()));
    connect(ui->location, SIGNAL(textEdited(const QString&)), this, SLOT(validate()));
    connect(ui->browseLocation, SIGNAL(clicked()), this, SLOT(browseLocation()));

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

void NewProjectDialog::browseLocation()
{
    QString location = QFileDialog::getExistingDirectory (this, "Select the location directory", getenv("HOME"), QFileDialog::ShowDirsOnly);
    qDebug() << location;
    ui->location->setText(location);
}

void NewProjectDialog::validate()
{
    qDebug() << "validate";
    if (ui->projectName->text() != "" && ui->location->text() != "" && QDir(ui->location->text()).exists()) {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    } else {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}

void NewProjectDialog::accept()
{
    qDebug() << "accept";
    Core::getProjectManager()->createNewProject(ui->projectName->text(), ui->location->text());
}
}
