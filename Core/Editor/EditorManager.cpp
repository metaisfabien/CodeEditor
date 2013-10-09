#include "Editor/EditorManager.h"
#include "Editor/Editor.h"

#include <QFile>
#include <QFileInfo>
#include <QDebug>

namespace PHPEditor {

EditorManager::EditorManager()
{
    addEditor("default", new Editor);
}

EditorManager::~EditorManager()
{
    map<QString, Editor*>::iterator editorIterator;
    for(editorIterator = mEditor.begin(); editorIterator != mEditor.end(); ++editorIterator) {
        delete editorIterator->second;
    }
}

void EditorManager::openFile(QString path)
{
    QFile file(path);
    if (file.exists()) {
        QString extension = QFileInfo(path).suffix();
        Editor *editor = getEditorByExtension(extension);
        if (!editor) {
            editor = getEditorById("default");
        }

        editor->openFile(path);
    } else {
        qDebug() << "File " + path + " does'nt exist";
    }
}



void EditorManager::addEditor(QString id, Editor *editor)
{
    mEditor.insert(std::make_pair<QString, Editor*>(id, editor));
}

Editor* EditorManager::getEditorByExtension(QString extension)
{
    return 0;
}

Editor* EditorManager::getEditorById(QString id)
{
    map<QString, Editor*>::iterator editorIterator;
    editorIterator = mEditor.find(id);

    if (editorIterator != mEditor.end()) {
        return editorIterator->second;
    }
    return 0;
}


}
