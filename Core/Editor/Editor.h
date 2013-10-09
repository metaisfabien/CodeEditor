#ifndef EDITOR_H
#define EDITOR_H

#include <QString>

namespace PHPEditor {
class Editor
{
public:
    Editor();
    void openFile(QString path);
};
}

#endif // EDITOR_H
