#ifndef WORKSPACE_DOCK_H
#define WORKSPACE_DOCK_H

#include <QString>
#include <QDockWidget>

namespace CE {
class Dock : public QDockWidget {
    Q_OBJECT
public:
    Dock(QString id, QString title);
    virtual ~Dock() = 0;
    void loadWidget();
    QString getId() const { return mId; }

public slots:
    void locationChanged(Qt::DockWidgetArea area);

protected:
    virtual QWidget *getChildWidget() = 0;

private:
    QString mId;
    bool mIsLoaded;
};
}
#endif // WORKSPACE_DOCKDATA_H
