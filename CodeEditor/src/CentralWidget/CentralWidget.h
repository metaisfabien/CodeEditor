#ifndef WIDGET_CENTRALWIDGET_H
#define WIDGET_CENTRALWIDGET_H

#include <QtWidgets>

namespace CE {
class TabWidgetManager;
class CentralWidget : public QWidget
{
Q_OBJECT
public:
    CentralWidget(TabWidgetManager *tabWidgetManager, QWidget *parent = 0);
};
}
#endif // WIDGET_CENTRALWIDGET_H
