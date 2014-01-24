#ifndef EDITOR_DEFAULT_H
#define EDITOR_DEFAULT_H

#include "Editor/Editor.h"
namespace CE {
class DefaultEditor : public Editor
{
public:
    DefaultEditor(QString id, QString name) : Editor(id, name) {}
    EditorWidget *getEditorWidget();
};
}

#endif // EDITOR_DEFAULT_H
