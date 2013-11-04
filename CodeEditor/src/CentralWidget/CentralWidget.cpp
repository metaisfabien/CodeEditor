#include "CentralWidget/CentralWidget.h"
#include "CentralWidget/TabWidget.h"
#include "CentralWidget/Splitter.h"
#include "CentralWidget/TabWidgetManager.h"

namespace CE {
CentralWidget::CentralWidget(TabWidgetManager *tabWidgetManager, QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();
    CentralWidgetSplitter *hSplitter = new CentralWidgetSplitter(HorrizontalSplitter);
    CentralWidgetTabWidget *tabWidget = tabWidgetManager->createTabWidget(hSplitter);

/*
    Splitter *vSplitter = new Splitter(VerticalSplitter, hSplitter);


    vSplitter->addWidget(tabWidget);

    hSplitter->addWidget(vSplitter);*/

    hSplitter->addWidget(tabWidget);
    layout->addWidget(hSplitter);


    //layout->addWidget(o);
    setLayout(layout);
}
}
