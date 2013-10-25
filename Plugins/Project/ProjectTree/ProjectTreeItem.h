#ifndef PROJECTTREEITEM_H
#define PROJECTTREEITEM_H

#include <QList>
#include <QVariant>

namespace CE {
namespace Project {

class ProjectTreeItem
{
public:
    enum ItemType {
        RootItemType = 0x1,
        ProjectItemType = 0x2,
        FileItemType = 0x4,
        DirectoryItemType = 0x8
    };

    explicit ProjectTreeItem(ProjectTreeItem *parent = 0, QString path = 0);
    ~ProjectTreeItem();

    void appendChild(ProjectTreeItem *child);

    ProjectTreeItem *child(int row);
    int childCount();
    int columnCount() const;

    int row() const;
    ProjectTreeItem *parent();

    bool hasLoadChidren() const { return mHasLoadChidren; }
    bool hasLoadSubChildren() const { return mHasLoadSubChildren; }
    void setHasLoadSubChildren(bool _hasLoadSubChildren) { mHasLoadSubChildren = _hasLoadSubChildren; }

    void loadChildren();
    void loadSubChildren();

    QIcon getIcon();

    void setName(QString name) { mName = name; }
    QString getName() const { return mName; }

    void setPath(QString path) { mPath = path; }
    QString getPath() const { return mPath; }

    ItemType getType() const { return mType; }

    void setIsExpand(bool isExpand) { mIsExpand = isExpand; }
    bool isExpand() const { return mIsExpand; }

private:
    QList<ProjectTreeItem*> childItems;
    QList<QVariant> itemData;
    ProjectTreeItem *mParentItem;

    bool mHasLoadChidren;
    bool mHasLoadSubChildren;

    QString mName;
    QString mPath;

    ItemType mType;

    bool mIsExpand;
};
}
}

#endif // PROJECTTREEITEM_H
