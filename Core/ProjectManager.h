#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QObject>
#include <vector>

namespace PHPEditor {
class NewProjectDialog;
class Project;
class ProjectManager : public QObject
{
    Q_OBJECT
public:
    ProjectManager();
    ~ProjectManager();
    void createNewProject(QString name, QString location);

public slots:
    void showNewProjectDialog();

private:
    void updateProjectsFile();
    void loadProjects();

    NewProjectDialog *newProjectDialog;
    std::vector<Project*> projects;
};
}
#endif // PROJECTMANAGER_H
