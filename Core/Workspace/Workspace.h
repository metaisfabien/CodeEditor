#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <vector>

#include <QString>
#include <QJsonObject>

#include "Export.h"

using namespace std;

namespace PHPEditor {
class Perspective;
class PHPEDITOR_EXPORT Workspace
{
public:
    Workspace();
    ~Workspace();
    void load();

    void test();
    Perspective* getCurrentPerspective();

private:
    void loadPerspectives(QJsonArray perspectives);
    void addDocksToPerpective(QJsonObject perspectiveObject, Perspective* perspective);

    std::vector<Perspective*> perspectives;
    Perspective *currentPerspective;
};
}
#endif // WORKSPACE_H
