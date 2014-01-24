#ifndef WIDGET_TABWIDGET_H
#define WIDGET_TABWIDGET_H

#include <QTabWidget>
#include <QTabBar>

#include "Export.h"

QT_BEGIN_NAMESPACE
class QDrag;
QT_END_NAMESPACE

namespace CE {
class CentralWidgetDropOverlay;
class CentralWidgetSplitter;
class CentralWidgetTabBar;
class EditorWidget;

enum DropArea {
    TopDropArea = 1,
    RightDropArea = 2,
    BottomDropArea = 3,
    LeftDropArea = 4,
    CenterDropArea = 5
};

class CentralWidgetTabWidget : public QTabWidget
{
Q_OBJECT
public:
    CentralWidgetTabWidget(CentralWidgetSplitter* parent);
    ~CentralWidgetTabWidget();

    EditorWidget *getEditorWidget(int tabIndex);
    void addEditorWidget(EditorWidget *editorWidget, QString label);
    CentralWidgetTabBar *tabBar();
    int getEditorWidgetIndex(EditorWidget *editorWidget);

public slots:
    void moveTab(int fromIndex, int toIndex);
    void startDragTab(QDrag* drag);
    void setParentSplitter(CentralWidgetSplitter *parent);
    CentralWidgetSplitter *getParentSplitter() const { return mParentSplitter; }
    void currentTabChanged(int tabIndex);
    void closeTab(const int& index);

protected:
    void dropEvent(QDropEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *);


    DropArea getDropArea(QPoint point);

private:
    //QString mOriginalStyleSheet;
    CentralWidgetDropOverlay *mDropAreaOverlay;
    CentralWidgetSplitter *mParentSplitter;
};
}


#endif // WIDGET_TABWIDGET_H
