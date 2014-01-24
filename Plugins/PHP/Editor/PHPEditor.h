#ifndef PHPEDITOR_H
#define PHPEDITOR_H

#include "Editor/Editor.h"


namespace CE {
class EditorWidget;
namespace PHP {
class PHPEditor : public Editor
{
public:
    PHPEditor(QString id, QString name) : Editor(id, name) { }

    EditorWidget *getEditorWidget();
};
}
}
#endif // PHPEDITOR_H
