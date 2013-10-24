#ifndef PERSPECTIVEDOCK_H
#define PERSPECTIVEDOCK_H

#include <QString>

namespace CE {
class Dock;
class PerspectiveDock
{
public:
    PerspectiveDock(QString id);
    QString getId() const { return mId; }

    Qt::DockWidgetArea getArea() const { return mArea; }
    void setArea(Qt::DockWidgetArea area) { mArea = area; }

    void setDock(Dock *dock) { mDock = dock; }
    Dock *getDock() const { return mDock; }

private:
    Qt::DockWidgetArea mArea;
    QString mId;
    Dock *mDock;
};
}
#endif // PERSPECTIVEDOCK_H
