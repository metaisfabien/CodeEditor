#ifndef OVERLAY_H
#define OVERLAY_H
#include <QWidget>
namespace CE{
class CentralWidgetDropOverlay : public QWidget
{
    Q_OBJECT
public:
    CentralWidgetDropOverlay(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
};
}

#endif // OVERLAY_H
