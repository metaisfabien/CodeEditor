#ifndef PHPEDITOR_H
#define PHPEDITOR_H

#include "Editor/Editor.h"


namespace CE {
namespace PHP {
class PHPEditor : public Editor
{
public:
    PHPEditor(QString id, QString name) : Editor(id, name) { }

    QWidget *getEditorWidget(QString fileContent, QString filePath);
};
}
}
#endif // PHPEDITOR_H
