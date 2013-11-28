#ifndef TEXTEDITORWIDGET_H
#define TEXTEDITORWIDGET_H

#include <Qsci/qsciscintilla.h>
#include <QTextEdit>

namespace CE {
class TextEditorWidget : public QTextEdit
{
    Q_OBJECT
public:
    TextEditorWidget(QWidget *parent) : QTextEdit(parent){}
};
}

#endif // TEXTEDITORWIDGET_H
