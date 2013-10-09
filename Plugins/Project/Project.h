#ifndef PROJECT_H
#define PROJECT_H

#include <QString>

namespace PHPEditor {
namespace Project {
class Project
{
public:
    Project(QString _name, QString _location) : name(_name), location(_location){}
    QString getName() { return name; }
    QString getLocation() { return location; }

private:
    QString name;
    QString location;
};
}
}

#endif // PROJECT_H
