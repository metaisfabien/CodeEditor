#include "Setting/Section/ExtensionItem.h"
#include "Editor/Editor.h"

#include <QLabel>
#include <QHBoxLayout>

namespace CE{
namespace Setting{
namespace Section{
namespace FileAssociation {

ExtensionItem::ExtensionItem(const QString &extension, Editor *editor)
{
    mEditor = editor;
    mWidget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout(mWidget);
    mExtensionLabel = new QLabel(extension);
    //mExtensionLabel->resize(QSize(300, 20));
    layout->addWidget(mExtensionLabel);
    QString editorName = "";
    if (editor) {
        editorName = editor->getName();
    }

    mEditorLabel = new QLabel(editorName);
    layout->addWidget(mEditorLabel);
  //  mWidget->setLayout(layout);
}

QString ExtensionItem::getExtension() const
{
    return mExtensionLabel->text();
}

}
}
}
}
