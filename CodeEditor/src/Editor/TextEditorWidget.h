#ifndef EDITOR_TEXTEDITORWIDGET_H
#define EDITOR_TEXTEDITORWIDGET_H

#include "Editor/EditorWidget.h"

class QsciScintilla;

namespace CE {
class TextEditorWidget : public EditorWidget
{
public:
    TextEditorWidget();
    bool isModified();
    void setText(QString text);
    void focus();
    void openFile(QString filePath);
    void save();

public slots:
    void onUpdateSettings();


protected:
    bool eventFilter(QObject *object, QEvent *event);
    QsciScintilla *mQsciScintilla;
    QString mCurrentFilePath;

private:
    QString getFileContent(QString path);
};
}

#endif // EDITOR_TEXTEDITORWIDGET_H
