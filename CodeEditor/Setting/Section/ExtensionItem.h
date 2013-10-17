#ifndef SettingSectionExtensionItem_h
#define SettingSectionExtensionItem_h

#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE

namespace CE{

class Editor;

namespace Setting{
namespace Section{
namespace FileAssociation {
class ExtensionItem : public QListWidgetItem
{
public:
    ExtensionItem (const QString &extension = QString::null, Editor *editor = 0);

    Editor *getEditor() const { return mEditor; }
    QWidget *getWidget() const { return mWidget; }
    QLabel *getExtensionLabel() const { return mExtensionLabel; }
    QString getExtension() const;
    QLabel *getEditorLabel() const { return mEditorLabel; }

private:
    Editor *mEditor;
    QWidget *mWidget;
    QLabel *mExtensionLabel;
    QLabel *mEditorLabel;
};
}
}
}
}

#endif // SettingSectionExtensionItem_h
