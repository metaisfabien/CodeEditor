#ifndef EDITOR_H
#define EDITOR_H

#include "Export.h"

#include <QString>

namespace CE {
class EditorWidget;
class CE_EXPORT Editor
{
public:
    Editor(QString id, QString name);

    QString getId() const { return mId; }
    QString getName() const { return mName; }

    virtual EditorWidget *getEditorWidget() = 0;

protected:

private:
    QString mId;
    QString mName;
};
}

#endif // EDITOR_H
