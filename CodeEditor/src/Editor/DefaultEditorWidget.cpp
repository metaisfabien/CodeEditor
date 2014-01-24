#include "Editor/DefaultEditorWidget.h"

#include "CodeEditor.h"
#include "Setting/SettingManager.h"

#include <Qsci/qsciscintilla.h>

#include <QSettings>

namespace CE {

DefaultEditorWidget::DefaultEditorWidget() : TextEditorWidget()
{
    mSettingManager = CodeEditor::getSettingManager();

    connect(mSettingManager, SIGNAL(updateSettings()), this, SLOT(onUpdateSettings()));

    QSettings *settings = mSettingManager->getSettings();

    //show line number
    if (settings->value("editors/show_line_number").toBool()) {
        mQsciScintilla->setMarginLineNumbers(1, true);
    }

    if (settings->value("editors/insert_space_for_tab").toBool()) {
        mQsciScintilla->setIndentationsUseTabs(false);
    } else {
        mQsciScintilla->setIndentationsUseTabs(true);
    }

    mQsciScintilla->setIndentationWidth	(4);
    //setWhitespaceVisibility(WhitespaceVisibility::WsVisible);
    //setWrapMode(WrapMode::WrapNone);
}

/**
 * @brief PHPEditorWidget::onUpdateSettings
 *
 * OnUpdateSettings slot, called when the settings is updated by the settings dialog
 *
 * Update the editor with the new setting
 */
void DefaultEditorWidget::onUpdateSettings()
{
    QSettings *settings = mSettingManager->getSettings();

    if (settings->value("editors/show_line_number").toBool()) {
        mQsciScintilla->setMarginLineNumbers(1, true);
    } else {
        mQsciScintilla->setMarginLineNumbers(0, false);
    }
}

}
