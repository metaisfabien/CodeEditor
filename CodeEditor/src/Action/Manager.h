#ifndef ACTION_MANAGER_H
#define ACTION_MANAGER_H

#include "Export.h"

#include <QString>
#include <QIcon>

QT_BEGIN_NAMESPACE
class QAction;
class QWidget;
QT_END_NAMESPACE

namespace CE {
class CE_EXPORT ActionManager
{
public:
    QAction *createAction(QString id, QString name, QWidget *parent, QIcon icone = 0);
    void addAction(QString id, QAction *action) { mActions[id] = action; }

    QAction *getAction(QString id);
    QHash<QString , QAction *> getActions() const { return mActions; }

private:
    QHash<QString , QAction *> mActions;
};
}
#endif // ACTION_MANAGER_H
