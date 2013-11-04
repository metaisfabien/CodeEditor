#ifndef CENTRALWIDGET_SPLITTER_H
#define CENTRALWIDGET_SPLITTER_H


#include "CentralWidget/TabWidget.h"

#include <QSplitter>

namespace CE {
class CentralWidgetDropOverlay;

enum SplitterType {
    VerticalSplitter = 0,
    HorrizontalSplitter = 1
};

class CentralWidgetSplitter : public QSplitter
{
    Q_OBJECT
public:
    CentralWidgetSplitter(SplitterType type, CentralWidgetSplitter *parent = 0);
    void dropTab(DropArea dropArea, int tabWidgetIndex, int fromTabWidgetIndex, int tabIndex);
    CentralWidgetSplitter *getParentSplitter() const { return mParentSplitter; }


protected:
    void dropEvent(QDropEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void dragMoveEvent(QDragMoveEvent *event);

private:
    SplitterType mType;
    CentralWidgetDropOverlay *mDropAreaOverlay;
    CentralWidgetSplitter *mParentSplitter;

    void clean(CentralWidgetTabWidget *fromTabWidget);
    void createChildSplitter(SplitterType type, CentralWidgetTabWidget *droppedTabWidget, CentralWidgetTabWidget *toTabWidget,
                                                                               DropArea dropArea, int toTabWidgetSpliterIndex);
    void resizeSplitter(int toTabWidgetSpliterIndex);


};
}
#endif // CENTRALWIDGET_SPLITTER_H
