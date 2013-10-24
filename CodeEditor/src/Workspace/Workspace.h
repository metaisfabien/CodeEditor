#ifndef WORKSPACE_H
#define WORKSPACE_H


#include "Export.h"
#include <vector>

#include <QString>
#include <QJsonObject>
#include <QObject>
#include <QSize>


using namespace std;

namespace CE {
class Perspective;
class MainWindow;
class DockManager;
class CE_EXPORT Workspace : public QObject
{
    Q_OBJECT
public:
    Workspace(MainWindow *mainWindow, DockManager *dockManager);
    ~Workspace();
    void load();

    Perspective* getCurrentPerspective();

public slots:
    void save();
    void updateWindowState();
    void updateWindowSize(QSize windowSize);

private:
    void restoreWindowSize();
    void addDocks();

    void loadPerspectives(QJsonArray perspectives);
    void addDocksToPerpective(QJsonObject perspectiveObject, Perspective* perspective);
    void addDocksToPerpectiveObject(QJsonObject *perspectiveObject, Perspective *perspective);

    std::vector<Perspective*> mPerspectives;
    Perspective *mCurrentPerspective;
    MainWindow *mMainWindow;
    DockManager *mDockManager;
};
}
#endif // WORKSPACE_H
