#include "Plugin.h"

#include "Core.h"
#include "Setting/SettingManager.h"
#include "Setting/SettingsDialog.h"

#include <QDebug>


namespace PHPEditor {
namespace PHP {
Plugin::Plugin()
{
    id = "php";

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
    connect(Core::getSettingManager(), SIGNAL(createSettingDialog(SettingsDialog*)), this, SLOT(onCreateSettingDialog(SettingsDialog*)));

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
