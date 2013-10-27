#ifndef WIDGET_TABBAR_H
#define WIDGET_TABBAR_H

#include <QTabBar>


QT_BEGIN_NAMESPACE
class QDrag;
QT_END_NAMESPACE

namespace CE {
class TabWidget;
class TabBar : public QTabBar
{
Q_OBJECT
public:
    TabBar(TabWidget* parent);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);

signals:
    void tabMoveRequested(int fromIndex, int toIndex);
    void startDrag(QDrag* drag);

private:
    QPoint mDragStartPos;
    int mDragCurrentIndex;
    TabWidget *mParent;
};
}
#endif // WIDGET_TABBAR_H
