#include "Widget/TabWidget.h"
#include "Widget/TabBar.h"

namespace CE {
TabWidget::TabWidget(QWidget* parent)
   : QTabWidget(parent)
{
    QTabBar* tabBar = new TabBar;
    connect(tabBar, SIGNAL(tabMoveRequested(int, int)), this, SLOT(moveTab(int, int)));
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
}
