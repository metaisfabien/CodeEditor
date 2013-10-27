#ifndef MENU_MENU_H
#define MENU_MENU_H

#include "Export.h"

#include <QMenu>

namespace CE {
class CE_EXPORT Menu : public QMenu
{
public:
    QMenu* menu(const QString& path, const QString& title = QString::null, const QIcon& icon = QIcon());

private:
    QHash<QString, QMenu*> mMenus;
};
}
#endif // MENU_MENU_H
