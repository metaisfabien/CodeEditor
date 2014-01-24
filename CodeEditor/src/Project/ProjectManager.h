#ifndef PROJECT_PROJECTMANAGER_H
#define PROJECT_PROJECTMANAGER_H

#include <QObject>
#include <QHash>

using namespace std;

namespace CE {
class Project;
class CTagsIndexer;
class ProjectManager : public QObject
{
Q_OBJECT
public:
    ProjectManager();
    ~ProjectManager();
    void createNewProject(QString name, QString location);
    QHash <int, Project*> getProjects() const { return mProjects; }

    void indexProjects();

public slots:
    void showNewProjectDialog();

signals:
    void buildProject(Project *project);

protected:
    void checkDb();
    void addProject(Project *project);
    void loadProjects();

    QHash <int, Project*>  mProjects;
    CTagsIndexer *mCTagsIndexer;
};
}
#endif // PROJECT_PROJECTMANAGER_H
