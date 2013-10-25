#ifndef MENU_MENU_H
#define MENU_MENU_H

#include <QMenu>

namespace CE {
class Menu : public QMenu
{
public:
    QMenu* path( const QString& path, const QString& title = QString::null, const QIcon& icon = QIcon());

private:
    QHash<QString, QMenu*> mMenus;
};
}
#endif // MENU_MENU_H
