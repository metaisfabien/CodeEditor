#ifndef WORKSPACE_DOCKDATA_H
#define WORKSPACE_DOCKDATA_H

#include <QString>

namespace CE {
class Dock;
class DockData {
public:
    DockData(QString id): mId(id), mArea(Qt::LeftDockWidgetArea) {}
    QString getId() { return mId; }
    void setArea(Qt::DockWidgetArea area) { mArea = area; }
    Qt::DockWidgetArea getArea() const { return mArea; }
    void setDock (Dock *dock) { mDock = dock; }
    Dock* getDock() const { return mDock; }

private:
    QString mId;
    Qt::DockWidgetArea mArea;
    Dock *mDock;
};
}
#endif // WORKSPACE_DOCKDATA_H
