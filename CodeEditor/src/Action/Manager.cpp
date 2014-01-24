#include "Action/Manager.h"

#include <QAction>

namespace CE {
QAction *ActionManager::createAction(QString id, QString name, QIcon icon, QWidget *parent)
{
    QAction *action = new QAction(icon, name, parent);
    addAction(id, action);

    return action;
}

QAction *ActionManager::getAction(QString id)
{
    if (mActions.contains(id)) {
        return mActions[id];
    }
    return 0;
}

}
