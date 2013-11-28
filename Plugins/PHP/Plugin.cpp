#include "Plugin.h"

#include "CodeEditor.h"
#include "Setting/SettingManager.h"
#include "Setting/SettingsDialog.h"
#include "Editor/EditorManager.h"

#include "Editor/PHPEditor.h"

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

    CodeEditor::getEditorManager()->addEditor(new PHPEditor("php", "PHP editor"));
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


QHash <QString, Dock*> Plugin::getDocks()
{
    QHash <QString, Dock*> docks;
    //docks["project_explorer"] = new ProjectExplorerDock(mProjectManager);

    return docks;
}

void Plugin::onCreateSettingDialog(SettingsDialog *SettingsDialog)
{
    qDebug() << "onCreateSettingDialog";
}
}
}
