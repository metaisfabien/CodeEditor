#include <QStringList>

#include "ProjectTreeItem.h"

//! [0]
ProjectTreeItem::ProjectTreeItem(const QList<QVariant> &data, ProjectTreeItem *parent)
{
    parentItem = parent;
    itemData = data;
}
//! [0]

//! [1]
ProjectTreeItem::~ProjectTreeItem()
{
    qDeleteAll(childItems);
}
//! [1]

//! [2]
void ProjectTreeItem::appendChild(ProjectTreeItem *item)
{
    childItems.append(item);
}
//! [2]

//! [3]
ProjectTreeItem *ProjectTreeItem::child(int row)
{
    return childItems.value(row);
}
//! [3]

//! [4]
int ProjectTreeItem::childCount() const
{
    return childItems.count();
}
//! [4]

//! [5]
int ProjectTreeItem::columnCount() const
{
    return itemData.count();
}
//! [5]

//! [6]
QVariant ProjectTreeItem::data(int column) const
{
    return itemData.value(column);
}
//! [6]

//! [7]
ProjectTreeItem *ProjectTreeItem::parent()
{
    return parentItem;
}
//! [7]

//! [8]
int ProjectTreeItem::row() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<ProjectTreeItem*>(this));

    return 0;
}
//! [8]
