#include "Menu/MenuBar.h"
namespace CE
{

/*!
  Appends a new QMenu with \a icon and \a title the a menu item or the menu bar if the menu not exist.
  Returns the new menu or the existing menu.

  \param path  The QMenu path to get
  \param title The menu title
  \param icon  The menu icon

  \sa QWidget::addAction(), QMenu::menuAction()
*/
QMenu *MenuBar::menu(const QString &path, const QString &title, const QIcon &icon)
{
    //if the menu does'nt exist
    if (!mMenus.contains(path)) {
        QStringList parts = path.split( "/" );
        QString curPath;

        // check/create parents
        for (int i = 0; i < parts.count(); i++) {
            curPath += "/" +parts.at( i );

            if (curPath[0] == '/') {
                curPath.remove(0, 1);
            }

            if (!mMenus.contains(curPath)) {
                QMenu* menu = 0;

                //if the parent is a QMenu
                if (curPath.contains('/')) {
                    const QString parentPath = curPath.left(curPath.lastIndexOf('/'));
                    menu = mMenus[parentPath]->addMenu(parts.at(i));
                //else the parent is the MenuBar
                } else {
                    menu = addMenu( parts.at( i ) );
                }
                //add the menu in the menus QHash
                menu->setObjectName(parts.at(i));
                menu->setTitle( parts.at( i ) );
                mMenus[curPath] = menu;
            }
        }
    }

    //Now update the menu data if it necessary
    QMenu* menu = mMenus[path];

    if (!title.isEmpty() && menu->title() != title) {
        menu->setTitle(title);
/*
        fPath = mActionsManager->fixedPath(path);
        if (!fPath.contains( '/' ) )
        {
            mActionsManager->setPathPartTranslation( fPath, title );
        }
*/
    }

    if (!icon.isNull() && menu->icon().cacheKey() != icon.cacheKey()) {
        menu->setIcon(icon);
    }

    return menu;
}


}
