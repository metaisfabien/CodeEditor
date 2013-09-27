#ifndef PROJECTTREEMODEL_H
#define PROJECTTREEMODEL_H

#include <QAbstractItemModel>

class ProjectTreeItem;
class ProjectManager;
class ProjectTreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    ProjectTreeModel(ProjectManager *projectManager, QObject *parent = 0);
    ~ProjectTreeModel();

    void addProject(QString name, QString location);
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    bool canFetchMore(const QModelIndex &parent) const;
    void fetchMore(const QModelIndex &parent);

private:
    ProjectTreeItem *mRootItem;
    ProjectManager *mProjectManager;
};

#endif // PROJECTTREEMODEL_H
