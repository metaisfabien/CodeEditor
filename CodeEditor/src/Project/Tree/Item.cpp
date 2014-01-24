#include "Project/Tree/Item.h"
#include "CodeEditor.h"
#include "Theme/ThemeManager.h"

#include <QStringList>
#include <QDir>
#include <QDirIterator>
#include <QDebug>
#include <QIcon>

namespace CE {
ProjectTreeItem::ProjectTreeItem(ProjectTreeItem *parent, QString path)
{
    mParentItem = parent;
    mPath = path;
    mIsExpand = false;
    mHasLoadChidren = false;
    mHasLoadSubChildren = false;

    //if item have no parent it's the root item
    if (!mParentItem) {
        mType = RootItemType;
    //if parent item is the root item it's a project
    } else if (mParentItem->getType() == RootItemType) {
        mType = ProjectItemType;
    } else {
        //if is a directory
        if (QDir(mPath).exists()) {
            mType = DirectoryItemType;
        //if is not a directory it's a file
        } else {
            mType = FileItemType;
        }
    }
}

ProjectTreeItem::~ProjectTreeItem()
{
    qDeleteAll(childItems);
}

/**
 * @brief ProjectTreeItem::appendChild
 *
 * Append a child ProjectTreeItem
 *
 * @param item
 */
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

/**
 * @brief ProjectTreeItem::columnCount
 *
 * Force the number of column to 1
 *
 * @return
 */
int ProjectTreeItem::columnCount() const
{
    return 1;
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
 *
 * Load child items
 *
 * if an item has'nt load child and have a parent
 * it's load child files and folder of the item
 */
void ProjectTreeItem::loadChildren()
{
   if (!mHasLoadChidren && parent()) {
       //if is a folder load children
       if (getType() == ProjectItemType || getType() == DirectoryItemType) {
            qDebug() << "loadChildren of item " + mName + " " + mPath;
            QDir dir = QDir(mPath);
            foreach (QString childName, dir.entryList(QDir::NoFilter, QDir::DirsFirst)) {
                if (childName != "." && childName != "..") {
                    ProjectTreeItem *item = new ProjectTreeItem(this, dir.absolutePath() +  "/" + childName);
                    item->setName(childName);
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

QIcon ProjectTreeItem::getIcon()
{
    if (getType() == ProjectItemType) {
        return CodeEditor::getThemeManager()->getIcon("project.png");
    } else if (getType() == DirectoryItemType) {
        if (isExpand()) {
            return CodeEditor::getThemeManager()->getIcon("folder-open.png");
        } else {
            return CodeEditor::getThemeManager()->getIcon("folder.png");
        }
    } else {
        return CodeEditor::getThemeManager()->getExtensionIcon(QFileInfo(getName()).suffix());
    }
}
}
