#ifndef DB_DBMANAGER_H
#define DB_DBMANAGER_H

#include <QSqlDatabase>

namespace CE {
class DbManager
{
    public:
        DbManager();
        QSqlDatabase getDb();
        QSqlQuery query();
        bool exec(QString sql);

    protected:
        QSqlDatabase mDb;
};
}

#endif // DB_DB_H
