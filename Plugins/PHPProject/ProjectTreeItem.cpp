#include <QStringList>
#include <QDir>
#include <QDirIterator>
#include <QDebug>

#include "ProjectTreeItem.h"

ProjectTreeItem::ProjectTreeItem(QString name, QString path, ProjectTreeItem *parent)
{
    qDebug() << "Create item " << name << " " << path;
    parentItem = parent;
    mName = name;
    mPath = path;
    mIsDir = QDir(path).exists();
    mIsExtend = false;
    mHasLoadChidren = false;
}

ProjectTreeItem::~ProjectTreeItem()
{
    qDeleteAll(childItems);
}

void ProjectTreeItem::appendChild(ProjectTreeItem *item)
{
    childItems.append(item);
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
    //return itemData.value(column);
    return mName;
}

ProjectTreeItem *ProjectTreeItem::parent()
{
    return parentItem;
}

int ProjectTreeItem::row() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<ProjectTreeItem*>(this));

    return 0;
}

void ProjectTreeItem::loadChildren()
{
   if (!mHasLoadChidren && (!parent() || !parent()->parent() ||  parent()->parent()->isExtend())) {
        qDebug() << "loadChildren of item " << mName << " " << mPath;
        if (mIsDir) {
            QDir dir = QDir(mPath);
            QStringList children = dir.entryList();

            int i = 0;
            while (i < children.count()) {
                if (children[i] != "." && children[i] != "..") {
                    ProjectTreeItem *item = new ProjectTreeItem(children[i], mPath + "/" + children[i], this);
                    appendChild(item);
                }
                ++i;
            }
        }
        mHasLoadChidren = true;
    }
}

