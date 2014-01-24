#ifndef CENTRALWIDGET_TABBAR_H
#define CENTRALWIDGET_TABBAR_H

#include <QTabBar>


QT_BEGIN_NAMESPACE
class QDrag;
QT_END_NAMESPACE

namespace CE {
class CentralWidgetTabWidget;
class CentralWidgetTabBar : public QTabBar
{
Q_OBJECT
public:
    CentralWidgetTabBar(CentralWidgetTabWidget *parent);
    void resetStyleSheet();

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    //void dropEvent(QDropEvent* event);

signals:
    void tabMoveRequested(int fromIndex, int toIndex);
    void startDrag(QDrag* drag);

private:
    QPoint mDragStartPos;
    int mDragCurrentIndex;
    QString mStyleSheet;
    CentralWidgetTabWidget *mParentTabWidget;
};
}
#endif // WIDGET_TABBAR_H
