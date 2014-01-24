#ifndef PROJECT_H
#define PROJECT_H

#include <QString>

namespace CE {
class Project
{
public:
    Project(int id, QString name, QString location) : mId(id), mName(name), mLocation(location){

    }

    int getId() const { return mId; }
    QString getName() const { return mName; }
    QString getLocation() const { return mLocation; }

private:
    int mId;
    QString mName;
    QString mLocation;

};

}

#endif // PROJECT_H
