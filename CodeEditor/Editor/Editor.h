#ifndef EDITOR_H
#define EDITOR_H

#include <QString>

namespace CE {
class Editor
{
public:
    Editor(QString id, QString name);

    QString getId() const { return mId; }
    QString getName() const { return mName; }

    void openFile(QString path);


private:
    QString mId;
    QString mName;
};
}

#endif // EDITOR_H
