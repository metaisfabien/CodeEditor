#include "Editor/EditorManager.h"
#include "Editor/Editor.h"
#include "Editor/Default.h"
#include "CodeEditor.h"
#include "Setting/SettingManager.h"

#include "CentralWidget/TabWidgetManager.h"
#include "CentralWidget/TabWidget.h"

#include "Editor/TextEditorWidget.h"

#include <QTextEdit>

#include <QSettings>
#include <QFile>
#include <QFileInfo>
#include <QDebug>

#include <Qsci/qsciscintilla.h>

namespace CE {

EditorManager::EditorManager()
{
    addEditor(new DefaultEditor("text", "Text editor"));
}

EditorManager::~EditorManager()
{
    map<QString, Editor*>::iterator editorIterator;
    for(editorIterator = mEditors.begin(); editorIterator != mEditors.end(); ++editorIterator) {
        delete editorIterator->second;
    }
}

/**
 * @brief EditorManager::openFile
 *
 * Open a file with an editor
 *
 * if the file is not already opened it get the editor widget and add it in the TabWidget
 * or show the tab contain the editor widget
 *
 *
 * @param path
 */
void EditorManager::openFile(QString path)
{
    qDebug() << "openFile " << path;
    QFile file(path);
    if (file.exists()) {
        TabWidgetManager *tabWidgetManager = CodeEditor::getTabWidgetManager();

        //if the file in no already open
        if (!mEditorWidgets.contains(path)) {
            QString fileContent = getFileContent(path);

            //Get the editor instance
            QString extension = QFileInfo(path).suffix();
            Editor *editor = getEditorByExtension(extension);
            if (!editor) {
                editor = getEditorById("text");
            }

            QWidget *widget = editor->getEditorWidget(fileContent, path);

            CentralWidgetTabWidget *tabWidget = tabWidgetManager->getFirstTabWidget();

            tabWidget->addTab(widget, QFileInfo(path).fileName());
            tabWidget->setCurrentWidget(widget);
            mEditorWidgets[path] = widget;
        } else {
            //the file is already open
            QWidget *widget = mEditorWidgets[path];

            //read the tabwidget list to get the tabwidget parent of the editor widget
            QWidgetList *tabWidgets = tabWidgetManager->getTabWidgets();
            for(int index = 0;index < tabWidgets->count(); index++) {
                CentralWidgetTabWidget *tabWidget = tabWidgetManager->getTabWidget(index);
                if (tabWidget->indexOf(widget) != -1) {
                    tabWidget->setCurrentWidget(widget);
                    break;
                }
            }

        }

    } else {
        qDebug() << "File " + path + " does'nt exist";
    }
}


QString EditorManager::getFileContent(QString path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    return file.readAll();
}


void EditorManager::addEditor(Editor *editor)
{
    mEditors.insert(std::make_pair<QString, Editor*>(editor->getId(), editor));
}

Editor* EditorManager::getEditorByExtension(QString extension)
{
    QSettings *settings = CodeEditor::getSettingManager()->getSettings();

    settings->beginGroup("file_association");
    QString editor = settings->value(extension).toString();
    settings->endGroup();

    if (editor != "") {
         return getEditorById(editor);
     }

    return 0;
}

Editor* EditorManager::getEditorById(QString id)
{
    map<QString, Editor*>::iterator editorIterator;
    editorIterator = mEditors.find(id);

    if (editorIterator != mEditors.end()) {
        return editorIterator->second;
    }
    return 0;
}

map<QString, Editor*> EditorManager::getEditors()
{
    return mEditors;
}

}
