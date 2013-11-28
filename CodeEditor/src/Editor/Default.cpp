#include "Editor/Default.h"
//#include "Editor/TextEditorWidget.h"
#include <Qsci/qsciscintilla.h>
namespace CE {

QWidget *DefaultEditor::getEditorWidget(QString fileContent, QString filePath)
{

    QsciScintilla *widget = new QsciScintilla();
    widget->setText(fileContent);

    return widget;
}

}
