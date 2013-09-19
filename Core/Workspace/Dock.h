#ifndef DOCK_H
#define DOCK_H

#include <QString>

namespace PHPEditor {
class Dock {
public:
    Dock(QString _id, QString _position): id(_id), position(_position) {}
    QString getId() { return id; }
    QString getPostion() { return position; }

private:
    QString id;
    QString position;
};
}
#endif // DOCK_H
