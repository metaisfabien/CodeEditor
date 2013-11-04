#ifndef CENTRALWIDGET_TABWIDGETMANAGER_H
#define CENTRALWIDGET_TABWIDGETMANAGER_H

#include <QWidgetList>

namespace CE {
class CentralWidgetTabWidget;
class CentralWidgetSplitter;
class TabWidgetManager {
public:
    TabWidgetManager();
    CentralWidgetTabWidget *createTabWidget(CentralWidgetSplitter *parent);

    int indexOf(CentralWidgetTabWidget *tabWidget);

    CentralWidgetTabWidget *getTabWidget(int index);
    void removeTab(int index);

    CentralWidgetTabWidget *getFirstTabWidget() { return getTabWidget(0); }
private:
    QWidgetList *mTabWidgets;
};
}
#endif // TABWIDGETMANAGER_H
