#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QObject>
#include <vector>

using namespace std;

class NewProjectDialog;
class Project;
class ProjectManager : public QObject
{
    Q_OBJECT
public:
    ProjectManager();
    ~ProjectManager();
    void createNewProject(QString name, QString location);
    vector<Project*> getProjects() const;

public slots:
    void showNewProjectDialog();

private:
    void updateProjectsFile();
    void loadProjects();

    NewProjectDialog *newProjectDialog;
    vector<Project*> projects;
};

#endif // PROJECTMANAGER_H
