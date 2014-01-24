#include "Editor/EditorManager.h"
#include "Editor/Editor.h"
#include "Editor/EditorWidget.h"
#include "Editor/Default.h"
#include "CodeEditor.h"
#include "Setting/SettingManager.h"
#include "CentralWidget/TabWidgetManager.h"
#include "CentralWidget/TabWidget.h"
#include "CentralWidget/TabBar.h"
#include "Action/Manager.h"

#include <QSettings>
#include <QDebug>
#include <QAction>
#include <QFile>
#include <QFileInfo>
#include <QTabBar>

#include <QStyle>

namespace CE {

EditorManager::EditorManager()
{
    mCurrentEditorWidget = 0;
    addEditor(new DefaultEditor("text", "Text editor"));

    QAction *saveAction = CodeEditor::getActionManager()->getAction("save");
    QObject::connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
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
            //Get the editor instance
            QString extension = QFileInfo(path).suffix();
            Editor *editor = getEditorByExtension(extension);
            if (!editor) {
                editor = getEditorById("text");
            }

            EditorWidget *editorWidget = editor->getEditorWidget();

            CentralWidgetTabWidget *tabWidget = tabWidgetManager->getFirstTabWidget();

            tabWidget->addEditorWidget(editorWidget, QFileInfo(path).fileName());
            editorWidget->openFile(path);
            tabWidget->setCurrentWidget(editorWidget);
            mEditorWidgets[path] = editorWidget;
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


void EditorManager::saveFile()
{
    if (mCurrentEditorWidget && mCurrentEditorWidget->isModified()) {
        mCurrentEditorWidget->save();
    }
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

/**
 * @brief EditorManager::setCurrentEditorWidget
 *
 * Set the current editor widget focus
 *
 * @param editorWidget
 */
void EditorManager::setCurrentEditorWidget(EditorWidget *editorWidget)
{
    if (editorWidget && mCurrentEditorWidget != editorWidget) {
        QAction *saveAction = CodeEditor::getActionManager()->getAction("save");
        if (editorWidget->isModified()) {
            saveAction->setDisabled(false);
        } else {
            saveAction->setDisabled(true);
        }

       if (mCurrentEditorWidget) {
            CentralWidgetTabWidget *currentTabWidget = mCurrentEditorWidget->getParentTabWidget();

            //update the style
            currentTabWidget->tabBar()->setProperty("currentTabBar", false);
            currentTabWidget->tabBar()->style()->unpolish(currentTabWidget->tabBar());
            currentTabWidget->tabBar()->style()->polish(currentTabWidget->tabBar());;
            currentTabWidget->tabBar()->update();
        }

        CentralWidgetTabWidget *tabWidget = editorWidget->getParentTabWidget();

        //update the style
        tabWidget->tabBar()->setProperty("currentTabBar", true);
        tabWidget->tabBar()->style()->unpolish(tabWidget->tabBar());
        tabWidget->tabBar()->style()->polish(tabWidget->tabBar());;
        tabWidget->tabBar()->update();
    }

    mCurrentEditorWidget = editorWidget;
}

}
