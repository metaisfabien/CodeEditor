#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

#include "Export.h"

#include <QString>
#include <QStringList>
#include <QHash>
#include <QSize>

namespace CE {
class PerspectiveDock;
class CE_EXPORT Perspective
{
public:
    Perspective(QString name, QString icone);
    ~Perspective();

    QString getName() const { return mName; }

    bool isCurrent() const { return mIsCurrent; }

    void addPerspectiveDock(PerspectiveDock *perspectiveDock);
    PerspectiveDock* getPerspectiveDock(QString id);
    QHash<QString, PerspectiveDock*> getPerspectiveDocks() const { return mPerspectiveDocks; }

    void setWindowState(Qt::WindowState windowState) { mWindowState = windowState; }
    Qt::WindowState getWindowState() const { return mWindowState; }

    void setWindowSize(int width, int height) { mWindowSize = QSize(width, height); }
    void setWindowSize(QSize size) { mWindowSize = size; }
    void setWindowSize(QString windowSize);
    QSize getWindowSize() const { return mWindowSize; }

    void updateDockArea(QString id, Qt::DockWidgetArea area);
private:
    QHash<QString, PerspectiveDock*> mPerspectiveDocks;
    QString mName;
    bool mIsCurrent;
    QString mIcone;

    QSize mWindowSize;

    Qt::WindowState mWindowState;

};
}

#endif // PERSPECTIVE_H
