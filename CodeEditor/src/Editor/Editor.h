#ifndef EDITOR_H
#define EDITOR_H

#include "Export.h"

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

#include <QString>

namespace CE {
class CE_EXPORT Editor
{
public:
    Editor(QString id, QString name);

    QString getId() const { return mId; }
    QString getName() const { return mName; }

    void openFile(QString path);
    virtual QWidget *getEditorWidget(QString fileContent, QString filePath) = 0;

protected:
    QString getFileContent(QString path);

private:
    QString mId;
    QString mName;
};
}

#endif // EDITOR_H
