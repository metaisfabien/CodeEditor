#ifndef PROJECTTREEVIEW_H
#define PROJECTTREEVIEW_H

#include <QTreeView>
#include <QString>

namespace PHPEditor {
namespace Project {
class ProjectManager;
class ProjectTreeModel;

class ProjectTreeView : public QTreeView
{
    Q_OBJECT
public:
    ProjectTreeView(ProjectManager *projectManager);

    void addProject(QString name, QString location);

public slots:
    void onDoubleClick (const QModelIndex &index);

private:
    ProjectTreeModel *mProjectTreeModel;
};
}
}

#endif // PROJECTTREEVIEW_H
