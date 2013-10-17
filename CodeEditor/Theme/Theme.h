#ifndef THEME_H
#define THEME_H

#include <QString>

namespace CE {
class Theme {
public:
    Theme(QString id, QString name, QString path);

    QString getId() const { return mId; }
    QString getName() const { return mName; }
    QString getPath() const { return mPath; }

private:
    QString mId;
    QString mName;
    QString mPath;
};
}
#endif // THEME_H
