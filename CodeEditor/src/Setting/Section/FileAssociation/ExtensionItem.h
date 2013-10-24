#ifndef SettingSectionExtensionItem_h
#define SettingSectionExtensionItem_h

#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
class QTreeWidget;
QT_END_NAMESPACE

namespace CE{

class Editor;
class SettingFileAssociationExtensionItem : public QTreeWidgetItem
{
public:
    SettingFileAssociationExtensionItem (QTreeWidget *parent);

    Editor *getEditor() const { return mEditor; }
    QString getExtension() const;

    void setEditor(Editor *editor);
    void setExtension (QString extension);


private:
    Editor *mEditor;
};
}

#endif // SettingSectionExtensionItem_h
