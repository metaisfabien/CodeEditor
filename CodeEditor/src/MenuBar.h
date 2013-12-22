#ifndef MENUBAR_H
#define MENUBAR_H

#include "Export.h"

#include <QMenuBar>
namespace CE {
class CE_EXPORT MenuBar : public QMenuBar
{
    Q_OBJECT

public:
    QMenu* menu( const QString& path, const QString& title = QString::null, const QIcon& icon = QIcon());

private:
    QHash<QString, QMenu*> mMenus;
};
}
#endif // MENUBAR_H
