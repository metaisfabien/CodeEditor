#ifndef TREEITEM_H
#define TREEITEM_H

#include <QList>
#include <QVariant>

//! [0]
class ProjectTreeItem
{
public:
    explicit ProjectTreeItem(const QList<QVariant> &data, ProjectTreeItem *parent = 0);
    ~ProjectTreeItem();

    void appendChild(ProjectTreeItem *child);

    ProjectTreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    ProjectTreeItem *parent();

private:
    QList<ProjectTreeItem*> childItems;
    QList<QVariant> itemData;
    ProjectTreeItem *parentItem;
};
//! [0]

#endif // TREEITEM_H
