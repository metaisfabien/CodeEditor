#ifndef PROJECTTREEVIEW_H
#define PROJECTTREEVIEW_H

#include <QTreeView>
#include <QString>

namespace CE {
class Menu;
namespace Project {
class ProjectManager;
class ProjectTreeModel;
class ProjectTreeItem;

class ProjectTreeView : public QTreeView
{
    Q_OBJECT
public:
    ProjectTreeView(ProjectManager *projectManager);

    void addProject(QString name, QString location);

signals:
    void createContextMenu(Menu *menu, ProjectTreeItem *item);

public slots:
    void onDoubleClick (const QModelIndex &index);
    void onExpand (const QModelIndex &index);
    void onCollapse (const QModelIndex &index);
    void onCustomContextMenuRequested(const QPoint& pos);

private:
    void showContextMenu(ProjectTreeItem *item, const QPoint& globalPos);
    void createContextMenuActions();

    ProjectTreeModel *mProjectTreeModel;
};
}
}

#endif // PROJECTTREEVIEW_H
