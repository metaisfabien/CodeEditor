#include "Plugin.h"

#include "CodeEditor.h"
#include "Setting/SettingManager.h"
#include "Setting/SettingsDialog.h"
#include <QDebug>


namespace CE {
namespace PHP {
Plugin::Plugin()
{
    mId = "php";

}

Plugin::~Plugin()
{

}

bool Plugin::load()
{
    qDebug() << "Load php plugin";
    /*
    mNewProjectAction = new QAction(QIcon(QApplication::applicationDirPath() +"/images/php_project.png"), tr("&PHP project"), this);
    mNewProjectAction->setStatusTip(tr("project"));

    connect(mNewProjectAction, SIGNAL(triggered()), this, SLOT(showNewProjectDialog()));

    Core::getMainWindow()->getNewMenu()->addAction(mNewProjectAction);
*/
    connect(CodeEditor::getSettingManager(), SIGNAL(createSettingDialog(SettingsDialog*)), this, SLOT(onCreateSettingDialog(SettingsDialog*)));

    return true;
}

bool Plugin::unLoad()
{
    return true;
}

void Plugin::onCreateSettingDialog(SettingsDialog *SettingsDialog)
{
    qDebug() << "onCreateSettingDialog";
}
}
}
