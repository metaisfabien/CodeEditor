#ifndef PROJECTTREEITEM_H
#define PROJECTTREEITEM_H

#include <QList>
#include <QVariant>

class ProjectTreeItem
{
public:
    explicit ProjectTreeItem(QString name, QString path, ProjectTreeItem *parent = 0);
    ~ProjectTreeItem();

    void appendChild(ProjectTreeItem *child);

    ProjectTreeItem *child(int row);
    int childCount();
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    ProjectTreeItem *parent();

    bool isDir() const { return mIsDir; }
    bool hasLoadChidren() const { return mHasLoadChidren; }
    void loadChildren();

    bool isExtend() const { return mIsExtend; }

private:
    QList<ProjectTreeItem*> childItems;
    QList<QVariant> itemData;
    ProjectTreeItem *parentItem;

    bool mIsDir;
    bool mIsExtend;
    bool mHasLoadChidren;

    QString mName;
    QString mPath;
};

#endif // PROJECTTREEITEM_H
