#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

#include "Export.h"

#include <QString>

#include <map>
#include <string>

namespace CE {
class Dock;
class CE_EXPORT Perspective
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
