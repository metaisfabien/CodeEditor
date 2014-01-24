#ifndef WORKSPACE_DOCK_H
#define WORKSPACE_DOCK_H

#include "Export.h"

#include <QString>
#include <QDockWidget>

namespace CE {
class CE_EXPORT Dock : public QDockWidget {
    Q_OBJECT
public:
    Dock(QString id, QString title);
    //~Dock() = 0;
    void loadWidget();
    QString getId() const { return mId; }
    virtual QWidget *getChildWidget() = 0;

public slots:
    void locationChanged(Qt::DockWidgetArea area);

protected:
    QString mId;
    bool mIsLoaded;
};
}
#endif // WORKSPACE_DOCKDATA_H
