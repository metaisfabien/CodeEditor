#include "CentralWidget/TabBar.h"
#include "CentralWidget/TabWidget.h"
#include "CentralWidget/Overlay.h"
#include "CentralWidget/TabWidgetManager.h"
#include "CentralWidget/Splitter.h"

#include "CodeEditor.h"

#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QApplication>

#include <QDebug>

namespace CE {

CentralWidgetTabBar::CentralWidgetTabBar(CentralWidgetTabWidget *parent)
    : QTabBar(parent)
{
    mParent = parent;
    //setAcceptDrops(true);
}

void CentralWidgetTabBar::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
        mDragStartPos = event->pos();

    QTabBar::mousePressEvent(event);
}

void CentralWidgetTabBar::mouseMoveEvent(QMouseEvent* event)
{
    // If the left button isn't pressed anymore then return
    if (!(event->buttons() & Qt::LeftButton))
        return;

    // If the distance is too small then return
    if ((event->pos() - mDragStartPos).manhattanLength() < QApplication::startDragDistance())
        return;

    // initiate Drag
    QDrag* drag = new QDrag(this);
    QMimeData* mimeData = new QMimeData;
    // a crude way to distinguish tab-reodering drags from other drags
    mimeData->setData("action", "drag-tab");

    int parentTabWidgetIndex = CodeEditor::getTabWidgetManager()->indexOf(mParent);
    mimeData->setData("from", QString::number(parentTabWidgetIndex).toUtf8());
    mimeData->setData("index", QString::number(currentIndex()).toUtf8());


    drag->setMimeData(mimeData);
    emit startDrag(drag);
    drag->exec();

    //mParent->getParentSplitter()->clean(mParent);
}

void CentralWidgetTabBar::dragEnterEvent(QDragEnterEvent* event)
{
    // Only accept if it's an tab-reordering request
    const QMimeData* m = event->mimeData();
    QStringList formats = m->formats();
    if (formats.contains("action") && (m->data("action") == "drag-tab")) {
        event->acceptProposedAction();
    }
}
/*
void TabBar::dropEvent(QDropEvent* event)
{
    const QMimeData* m = event->mimeData();
    QStringList formats = m->formats();
    if (formats.contains("action") && (m->data("action") == "drag-tab")) {
        qDebug() << "TabBar::dropEvent" + m->data("action");
        if (formats.contains("from")) {
            qDebug() << "From " + m->data("from");
            if (m->data("from") == mParent->getId()) {
                qDebug() << "same tabBar";
            } else {

                qDebug() << "other tabBar";
            }
        }
    }
    int fromIndex = tabAt(mDragStartPos);
    int toIndex   = tabAt(event->pos());

    // Tell interested objects that
    if (fromIndex != toIndex)
       emit tabMoveRequested(fromIndex, toIndex);

    event->acceptProposedAction();
}*/
}
