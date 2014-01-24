#include "Editor/EditorWidget.h"
#include "CodeEditor.h"
#include "Editor/EditorManager.h"
#include "Action/Manager.h"
#include "CentralWidget/TabWidget.h"
#include "CentralWidget/TabBar.h"

#include <QAction>

namespace CE {
void EditorWidget::focus()
{
    CodeEditor::getEditorManager()->setCurrentEditorWidget(this);
}

void EditorWidget::save()
{
    QAction *saveAction = CodeEditor::getActionManager()->getAction("save");
    saveAction->setDisabled(true);
}

/**
 * @brief EditorWidget::change
 *
 * Slot called when the widget content change
 *
 *
 */
void EditorWidget::change()
{
    bool disabled = true;
    QString tabName = getTabText();

    if (isModified()) {
        disabled = false;
        tabName = tabName + " *";
    }

    if (CodeEditor::getEditorManager()->getCurrentEditorWidget() == this) {
        QAction *saveAction = CodeEditor::getActionManager()->getAction("save");
        saveAction->setDisabled(disabled);
    }

    int index = mParentTabWidget->getEditorWidgetIndex(this);
    mParentTabWidget->setTabText(index, tabName);
}
}
