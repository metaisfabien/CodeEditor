#include <QStringList>
#include <QDir>
#include <QDirIterator>
#include <QDebug>

#include "ProjectTreeItem.h"

namespace CE {
namespace Project {
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

/**
 * @brief ProjectTreeItem::loadChildren
 * if an item has'nt load child and have a parent
 * it's load child files and folder of the item
 */
void ProjectTreeItem::loadChildren()
{
   if (!mHasLoadChidren && parent()) {
       qDebug() << "loadChildren of item " + mName + " " + mPath;
       //if is a folder load child
        if (QDir(mPath).exists()) {
            QDir dir = QDir(mPath);
            foreach (QString dirName, dir.entryList()) {
                if (dirName != "." && dirName != "..") {
                    ProjectTreeItem *item = new ProjectTreeItem(this);
                    item->setName(dirName);
                    item->setPath(dir.absolutePath() +  "/" + dirName);
                    appendChild(item);
                }
            }
        }

        //flag child has been laoded
        mHasLoadChidren = true;

        //flag sub child of the parent has been loaded
        if (parent()) {
            parent()->setHasLoadSubChildren(true);
        }
    } else {
        //qDebug() << "can't loadChildren of item " << mName << " " << mPath;
    }
}

void ProjectTreeItem::loadSubChildren()
{
    int i = 0;
    while (i < childItems.count()) {
        childItems[i]->loadChildren();
        ++i;
    }
}
}
}
