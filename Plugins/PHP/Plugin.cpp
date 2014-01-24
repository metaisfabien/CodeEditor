#include "Plugin.h"
#include "Builder.h"

#include "CodeEditor.h"
#include "Setting/SettingManager.h"
#include "Setting/SettingsDialog.h"
#include "Editor/EditorManager.h"
#include "Editor/PHPEditor.h"

#include "Project/ProjectManager.h"
#include "Project/Project.h"

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

    connect(CodeEditor::getProjectManager(), SIGNAL(buildProject(Project*)), this, SLOT(buildProject(Project*)));
    connect(CodeEditor::getSettingManager(), SIGNAL(createSettingDialog(SettingsDialog*)), this, SLOT(onCreateSettingDialog(SettingsDialog*)));

    return true;
}

bool Plugin::unLoad()
{
    return true;
}


void Plugin::buildProject(Project* project)
{
    Builder *builder = new Builder;
    builder->build(project);
}

void Plugin::onCreateSettingDialog(SettingsDialog *SettingsDialog)
{
    qDebug() << "onCreateSettingDialog";
}
}
}
