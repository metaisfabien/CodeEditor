#include <QStringList>
#include <QDir>
#include <QDirIterator>
#include <QDebug>

#include "ProjectTreeItem.h"

ProjectTreeItem::ProjectTreeItem(ProjectTreeItem *parent)
{
    mParentItem = parent;
    mHasLoadChidren = false;
    mHasLoadSubChildren = false;
}

ProjectTreeItem::~ProjectTreeItem()
{
    qDeleteAll(childItems);
}

void ProjectTreeItem::appendChild(ProjectTreeItem *item)
{
    childItems.append(item);
    //qDebug() << "Add item " << item->getName() << ":" << item->getPath() << " to " << getName();
}

ProjectTreeItem *ProjectTreeItem::child(int row)
{
    loadChildren();
    return childItems.value(row);
}

int ProjectTreeItem::childCount()
{
    loadChildren();
    return childItems.count();
}

int ProjectTreeItem::columnCount() const
{
    return 1;
    return itemData.count();
}

QVariant ProjectTreeItem::data(int column) const
{
    return mName;
}

ProjectTreeItem *ProjectTreeItem::parent()
{
    return mParentItem;
}

int ProjectTreeItem::row() const
{
    if (mParentItem)
        return mParentItem->childItems.indexOf(const_cast<ProjectTreeItem*>(this));

    return 0;
}

void ProjectTreeItem::loadChildren()
{
   if (!mHasLoadChidren && parent()) {
        //qDebug() << "loadChildren of item " << mName << " " << mPath;
        if (QDir(mPath).exists()) {
            QDir dir = QDir(mPath);
            QStringList children = dir.entryList(QDir::Dirs);

            int i = 0;
            while (i < children.count()) {
                if (children[i] != "." && children[i] != "..") {
                    ProjectTreeItem *item = new ProjectTreeItem(this);
                    item->setName(children[i]);
                    item->setPath(getPath() + "/" + children[i]);
                    appendChild(item);
                }
                ++i;
            }
        }
        mHasLoadChidren = true;
        if (parent()) {
            parent()->setHasLoadSubChildren(true);
        }
    }/* else {
        qDebug() << "can't loadChildren of item " << mName << " " << mPath;
   }*/
}

void ProjectTreeItem::loadSubChildren()
{
    int i = 0;
    while (i < childItems.count()) {
        childItems[i]->loadChildren();
        ++i;
    }
}
