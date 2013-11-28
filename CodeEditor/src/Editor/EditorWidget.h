#ifndef EDITORWIDGET_H
#define EDITORWIDGET_H

#include "Export.h"

#include <QString>
#include <QWidget>

namespace CE {
class CE_EXPORT EditorWidget
{
public:
    EditorWidget(QString filePath) { mFilePath = filePath; }

    QString getFilePath() const {
        return mFilePath;
    }
protected:
    QString mFilePath;
};
}
#endif // EDITORWIDGET_H
