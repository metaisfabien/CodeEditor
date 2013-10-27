#include "Widget/TabWidget.h"
#include "Widget/TabBar.h"

#include <QDrag>
#include <QBuffer>
#include <QPainter>
#include <QDebug>

namespace CE {
TabWidget::TabWidget(QString id, QWidget* parent)
   : QTabWidget(parent)
{
    qDebug() << "TabWidget::TabWidget";
    mId = id;
    setAcceptDrops(true);

    QTabBar* tabBar = new TabBar(this);
    connect(tabBar, SIGNAL(tabMoveRequested(int, int)), this, SLOT(moveTab(int, int)));
    connect(tabBar, SIGNAL(startDrag(QDrag*)), this, SLOT(startDragTab(QDrag*)));
    setTabBar(tabBar); // Replace default tab bar with our own
}

void TabWidget::moveTab(int fromIndex, int toIndex)
{
    // Save the desired tab properties
    QWidget* w = widget(fromIndex);
    QIcon icon = tabIcon(fromIndex);
    QString text = tabText(fromIndex);

    // remove the tab and insert a new tab
    // with the stored properties
    removeTab(fromIndex);
    insertTab(toIndex, w, icon, text);
    setCurrentIndex(toIndex);
}

/**
 * @brief TabWidget::startDragTab
 *
 * Slot call when an tab of this tab widget start to drag
 *
 * it create a pixmap of the current tab widget set transparency on it
 * and show it
 *
 * @param drag
 */
void TabWidget::startDragTab(QDrag* drag)
{
    QPixmap pixmap(currentWidget()->size());
    currentWidget()->render(&pixmap);
    pixmap = pixmap.scaled(200, 200, Qt::KeepAspectRatio);

    QPixmap transparent(pixmap.size());
    // Do transparency
    transparent.fill(Qt::transparent);
    QPainter p(&transparent);
    p.setCompositionMode(QPainter::CompositionMode_Source);
    p.drawPixmap(0, 0, pixmap);
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    // Set transparency level to 150 (possible values are 0-255)
    // The alpha channel of a color specifies the transparency effect,
    // 0 represents a fully transparent color, while 255 represents
    // a fully opaque color.
    p.fillRect(transparent.rect(), QColor(0, 0, 0, 150));
    p.end();

    // Set original picture's reference to new transparent one
    pixmap = transparent;
    drag->setPixmap(pixmap);
}
}
