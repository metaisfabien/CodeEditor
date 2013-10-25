#ifndef WIDGET_TABBAR_H
#define WIDGET_TABBAR_H

#include <QTabBar>

namespace CE {
class TabBar : public QTabBar
{
Q_OBJECT
public:
    TabBar(QWidget* parent=0);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);

signals:
    void tabMoveRequested(int fromIndex, int toIndex);

private:
    QPoint mDragStartPos;
    int mDragCurrentIndex;
};
}
#endif // WIDGET_TABBAR_H
