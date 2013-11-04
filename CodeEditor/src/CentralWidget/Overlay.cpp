#include "CentralWidget/Overlay.h"

#include <QPainter>
#include <QPen>
#include <QDebug>

namespace CE{
CentralWidgetDropOverlay::CentralWidgetDropOverlay(QWidget *parent)
    : QWidget(parent)
{
    setPalette(Qt::transparent);
    setAttribute(Qt::WA_TransparentForMouseEvents);
}

void CentralWidgetDropOverlay::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen = QPen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawRect(QRect(0, 0, width(), height()));
}
}
