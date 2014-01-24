#include "Editor/Default.h"
#include "Editor/DefaultEditorWidget.h"
namespace CE {

EditorWidget *DefaultEditor::getEditorWidget()
{
    return new DefaultEditorWidget();
}

}
