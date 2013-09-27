#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QObject>
#include <vector>

using namespace std;

class Project;
class ProjectManager : public QObject
{
    Q_OBJECT
public:
    ProjectManager();
    ~ProjectManager();
    void createNewProject(QString name, QString location);
    vector<Project*> getProjects() const;

private:
    void updateProjectsFile();
    void loadProjects();

    vector<Project*> projects;
};

#endif // PROJECTMANAGER_H
