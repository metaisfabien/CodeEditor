#include "Setting/Section/FileAssociation/ExtensionItem.h"

#include "Editor/Editor.h"


namespace CE{
SettingFileAssociationExtensionItem::SettingFileAssociationExtensionItem(QTreeWidget *parent) : QTreeWidgetItem(parent)
{

}
void SettingFileAssociationExtensionItem::setEditor(Editor *editor)
{
    mEditor = editor;
    setText(1, editor->getName());
}

void SettingFileAssociationExtensionItem::setExtension (QString extension)
{
    setText(0, extension);
}


QString SettingFileAssociationExtensionItem::getExtension() const
{
    return text(0);
}


}
