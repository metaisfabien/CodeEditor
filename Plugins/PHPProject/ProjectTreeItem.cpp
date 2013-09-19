#include <QStringList>
#include <QDir>
#include <QDirIterator>
#include <QDebug>

#include "ProjectTreeItem.h"

ProjectTreeItem::ProjectTreeItem(QString name, QString path, ProjectTreeItem *parent)
{
    parentItem = parent;
    mName = name;
    mPath = path;
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
    return itemData.count();
}

QVariant ProjectTreeItem::data(int column) const
{
    return itemData.value(column);
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
    if (!mHasLoadChidren) {
        if (mIsDir) {
            QStringList children;
            QDirIterator directories(mPath, QDir::Dirs | QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
            while(directories.hasNext()){
                directories.next();
                qDebug() << directories.filePath();
            }
        }
        mHasLoadChidren = true;
    }
}

