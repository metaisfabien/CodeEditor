#include "Editor/PHPEditor.h"
#include "Editor/PHPEditorWidget.h"

namespace CE {
namespace PHP {

QWidget *PHPEditor::getEditorWidget(QString fileContent, QString filePath)
{
    PHPEditorWidget *widget = new PHPEditorWidget();
    widget->setText(fileContent);

    return widget;
}
}
}
