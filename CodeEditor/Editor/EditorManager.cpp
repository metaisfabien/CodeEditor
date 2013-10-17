#include "Editor/EditorManager.h"
#include "Editor/Editor.h"

#include <QFile>
#include <QFileInfo>
#include <QDebug>

namespace CE {

EditorManager::EditorManager()
{
    addEditor(new Editor("text", "Text editor"));
}

EditorManager::~EditorManager()
{
    map<QString, Editor*>::iterator editorIterator;
    for(editorIterator = mEditors.begin(); editorIterator != mEditors.end(); ++editorIterator) {
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
            editor = getEditorById("text");
        }

        editor->openFile(path);
    } else {
        qDebug() << "File " + path + " does'nt exist";
    }
}



void EditorManager::addEditor(Editor *editor)
{
    mEditors.insert(std::make_pair<QString, Editor*>(editor->getId(), editor));
}

Editor* EditorManager::getEditorByExtension(QString extension)
{
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
