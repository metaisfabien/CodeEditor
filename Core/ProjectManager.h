#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QObject>

namespace PHPEditor {
class ProjectManager : public QObject
{
    Q_OBJECT
public:
    ProjectManager();
    void createNewProject(QString name, QString location);

public slots:
    void showNewProjectDialog();

private:
    bool isShowNewProjectDialog;
};
}
#endif // PROJECTMANAGER_H
