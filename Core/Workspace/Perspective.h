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
    Perspective(QString name, QString icone);
    ~Perspective();

    void addDock(Dock *dock);
    Dock* getDock(QString id);

private:
    std::map<QString, Dock*> mDocks;
    QString mName;
    QString mIcone;
};
}

#endif // PERSPECTIVE_H
