#ifndef WIDGET_TABWIDGET_H
#define WIDGET_TABWIDGET_H

#include <QTabWidget>

namespace CE {
class TabWidget : public QTabWidget
{
Q_OBJECT
public:
    TabWidget(QWidget* parent=0);
public slots:
    void moveTab(int fromIndex, int toIndex);
};
}

#endif // WIDGET_TABWIDGET_H
