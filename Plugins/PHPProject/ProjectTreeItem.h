#ifndef PROJECTTREEITEM_H
#define PROJECTTREEITEM_H

#include <QList>
#include <QVariant>

class ProjectTreeItem
{
public:
    explicit ProjectTreeItem(ProjectTreeItem *parent = 0);
    ~ProjectTreeItem();

    void appendChild(ProjectTreeItem *child);

    ProjectTreeItem *child(int row);
    int childCount();
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    ProjectTreeItem *parent();

    bool hasLoadChidren() const { return mHasLoadChidren; }
    bool hasLoadSubChildren() const { return mHasLoadSubChildren; }
    void setHasLoadSubChildren(bool _hasLoadSubChildren) { mHasLoadSubChildren = _hasLoadSubChildren; }
    void setName(QString name) { mName = name; }
    QString getName() const { return mName; }
    void setPath(QString path) { mPath = path; }
    QString getPath() const { return mPath; }
    void loadChildren();
    void loadSubChildren();

private:
    QList<ProjectTreeItem*> childItems;
    QList<QVariant> itemData;
    ProjectTreeItem *mParentItem;

    bool mHasLoadChidren;
    bool mHasLoadSubChildren;

    QString mName;
    QString mPath;
};

#endif // PROJECTTREEITEM_H
