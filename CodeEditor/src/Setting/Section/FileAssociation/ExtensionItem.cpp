#include "Setting/Section/FileAssociation/ExtensionItem.h"
#include "Editor/Editor.h"

#include <QLabel>
#include <QHBoxLayout>

namespace CE{
SettingFileAssociationExtensionItem::SettingFileAssociationExtensionItem(const QString &extension, Editor *editor)
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

QString SettingFileAssociationExtensionItem::getExtension() const
{
    return mExtensionLabel->text();
}
}
