#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

#include "Export.h"

#include <QString>

#include <map>
#include <string>

namespace PHPEditor {
class Dock;
class PHPEDITOR_EXPORT Perspective
{
public:
    Perspective(QString _name, QString _icone);
    ~Perspective();

    void addDock(Dock *dock);
    Dock* getDock(QString id);

private:
    std::map<std::string, Dock*> docks;
    QString name;
    QString icone;
};
}

#endif // PERSPECTIVE_H
