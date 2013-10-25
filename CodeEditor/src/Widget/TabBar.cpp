#include "Widget/TabBar.h"

#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QApplication>

namespace CE {

TabBar::TabBar(QWidget* parent)
    : QTabBar(parent)
{
    setAcceptDrops(true);
}

void TabBar::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
        mDragStartPos = event->pos();

    QTabBar::mousePressEvent(event);
}

void TabBar::mouseMoveEvent(QMouseEvent* event)
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
    mimeData->setData("action", "move-tab") ;
    drag->setMimeData(mimeData);
    drag->exec();
}

void TabBar::dragEnterEvent(QDragEnterEvent* event)
{
    // Only accept if it's an tab-reordering request
    const QMimeData* m = event->mimeData();
    QStringList formats = m->formats();
    if (formats.contains("action") && (m->data("action") == "move-tab")) {
        event->acceptProposedAction();
    }
}

void TabBar::dropEvent(QDropEvent* event)
{
    int fromIndex = tabAt(mDragStartPos);
    int toIndex   = tabAt(event->pos());

    // Tell interested objects that
    if (fromIndex != toIndex)
       emit tabMoveRequested(fromIndex, toIndex);

    event->acceptProposedAction();
}
}
