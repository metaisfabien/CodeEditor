#include "CentralWidget/TabWidgetManager.h"
#include "CentralWidget/TabWidget.h"

#include <QWidgetList>
#include <QDebug>

namespace CE {
TabWidgetManager::TabWidgetManager()
{
    mTabWidgets = new QWidgetList;
}

CentralWidgetTabWidget *TabWidgetManager::createTabWidget(CentralWidgetSplitter *parent)
{
    qDebug() << "create tab widget ";
    CentralWidgetTabWidget *tabWidget = new CentralWidgetTabWidget(parent);
    mTabWidgets->append(tabWidget);
    return tabWidget;
}


int TabWidgetManager::indexOf(CentralWidgetTabWidget *tabWidget)
{
    return mTabWidgets->indexOf(tabWidget);
}

CentralWidgetTabWidget *TabWidgetManager::getTabWidget(int index)
{
    return  qobject_cast<CentralWidgetTabWidget *>(mTabWidgets->at(index));
}

void TabWidgetManager::removeTab(int index)
{
    //TabWidget *tableWidget = getTabWidget(index);
    mTabWidgets->removeAt(index);
   // delete tableWidget;
}
}
