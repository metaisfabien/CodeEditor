#include "ProjectTree/ProjectTreeView.h"
#include "ProjectTree/ProjectTreeModel.h"
#include "ProjectTree/ProjectTreeItem.h"

#include "ProjectManager.h"

#include "Core.h"
#include "Editor/EditorManager.h"

#include <QHeaderView>
#include <QTreeWidget>
#include <QDebug>

namespace PHPEditor {
namespace Project {
ProjectTreeView::ProjectTreeView(ProjectManager *projectManager)
{
    mProjectTreeModel = new ProjectTreeModel(projectManager);
    //hide the tree header
    header()->close();
    setModel(mProjectTreeModel);
    setStyleSheet(QString("QTreeView::branch { border-image: none; }"));
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(this, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(onDoubleClick(const QModelIndex&)));
}

void ProjectTreeView::onDoubleClick (const QModelIndex &index)
{
    if (index.isValid()) {
        ProjectTreeItem *item = static_cast<ProjectTreeItem*>(index.internalPointer());
        qDebug() << "Double click on item " + item->getPath();
        Core::getEditorManager()->openFile(item->getPath());
    }
}


void ProjectTreeView::addProject(QString name, QString location)
{
    mProjectTreeModel->addProject(name, location);
}
}
}
