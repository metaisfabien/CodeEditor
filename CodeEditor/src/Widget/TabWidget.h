#ifndef WIDGET_TABWIDGET_H
#define WIDGET_TABWIDGET_H

#include <QTabWidget>

QT_BEGIN_NAMESPACE
class QDrag;
QT_END_NAMESPACE

namespace CE {
class TabWidget : public QTabWidget
{
Q_OBJECT
public:
    TabWidget(QString id, QWidget* parent=0);
    QString getId() const { return mId; }

public slots:
    void moveTab(int fromIndex, int toIndex);
    void startDragTab(QDrag* drag);

private:
    QString mId;
};
}

#endif // WIDGET_TABWIDGET_H
