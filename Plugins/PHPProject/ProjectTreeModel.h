#ifndef PROJECTTREEMODEL_H
#define PROJECTTREEMODEL_H

#include <QAbstractItemModel>

class ProjectTreeItem;
class ProjectTreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    ProjectTreeModel(QString name, QString path, QObject *object = 0);
    ~ProjectTreeModel();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
private:

    void setupModelData(const QStringList &lines, ProjectTreeItem *parent);
    ProjectTreeItem *rootItem;
};

#endif // PROJECTTREEMODEL_H
