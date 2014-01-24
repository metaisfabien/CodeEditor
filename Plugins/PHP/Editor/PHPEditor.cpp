#include "Editor/PHPEditor.h"
#include "Editor/EditorWidget.h"
#include "Editor/PHPEditorWidget.h"

namespace CE {
namespace PHP {

EditorWidget *PHPEditor::getEditorWidget()
{
    return new PHPEditorWidget();
}
}
}
