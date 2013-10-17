#include "NewProjectDialog.h"
#include "ProjectManager.h"
#include "plugin.h"

#include "CodeEditor.h"

#include <QFileDialog>
#include <QDebug>

namespace CE {
namespace Project {
NewProjectDialog::NewProjectDialog(Plugin *phpPlugin, QWidget *parent) :
    QDialog(parent)
{
    mPhpPlugin = phpPlugin;
    setupUi(this);
    connect(projectName, SIGNAL(textChanged(const QString&)), this, SLOT(validate()));
    connect(location, SIGNAL(textChanged(const QString&)), this, SLOT(validate()));
    connect(location, SIGNAL(textEdited(const QString&)), this, SLOT(validate()));
    connect(browseLocation, SIGNAL(clicked()), this, SLOT(openBrowseLocationDialog()));

    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

NewProjectDialog::~NewProjectDialog()
{

}

void NewProjectDialog::clean()
{
    projectName->setText("");
    location->setText("");
}

QString NewProjectDialog::getName()
{
    return projectName->text();
}

QString NewProjectDialog::getLocation()
{
    return location->text();
}

void NewProjectDialog::openBrowseLocationDialog()
{
    QString dirPath = QFileDialog::getExistingDirectory (this, "Select the location directory", getenv("HOME"), QFileDialog::ShowDirsOnly);
    location->setText(dirPath);
}

void NewProjectDialog::validate()
{
    if (getName() != "" && getLocation() != "" && QDir(getLocation()).exists()) {
        buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    } else {
        buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}

void NewProjectDialog::accept()
{
    mPhpPlugin->createNewProject(getName(), getLocation());
    clean();
    QDialog::accept();

}

void NewProjectDialog::reject()
{
    clean();
    QDialog::reject();
}
}
}
