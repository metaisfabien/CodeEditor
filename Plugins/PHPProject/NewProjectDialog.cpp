#include "ui_NewProjectDialog.h"
#include "NewProjectDialog.h"
#include "ProjectManager.h"
#include "PHPProject.h"

#include "Core.h"

#include <QFileDialog>
#include <QDebug>

using namespace PHPEditor;

NewProjectDialog::NewProjectDialog(PHPProject *phpProject, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    mPhpProject = phpProject;
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

void NewProjectDialog::clean()
{
    ui->projectName->setText("");
    ui->location->setText("");
}

QString NewProjectDialog::getName()
{
    return ui->projectName->text();
}

QString NewProjectDialog::getLocation()
{
    return ui->location->text();
}

void NewProjectDialog::browseLocation()
{
    QString location = QFileDialog::getExistingDirectory (this, "Select the location directory", getenv("HOME"), QFileDialog::ShowDirsOnly);
    qDebug() << location;
    ui->location->setText(location);
}

void NewProjectDialog::validate()
{
    if (getName() != "" && getLocation() != "" && QDir(getLocation()).exists()) {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    } else {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}

void NewProjectDialog::accept()
{
    mPhpProject->createNewProject(getName(), getLocation());
    clean();
    QDialog::accept();

}

void NewProjectDialog::reject()
{
    clean();
    QDialog::reject();
}
