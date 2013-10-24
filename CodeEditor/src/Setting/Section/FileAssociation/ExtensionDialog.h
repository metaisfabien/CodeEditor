#ifndef SettingSectionExtensionDialog_h
#define SettingSectionExtensionDialog_h


#include "ui_SettingFileAssociationExtensionDialog.h"

namespace CE{
class SettingFileAssociationSection;
class Editor;
class SettingFileAssociationExtensionDialog : public QDialog, public Ui::SettingFileAssociationExtensionDialog {
public:
    SettingFileAssociationExtensionDialog(QWidget *parent, SettingFileAssociationSection* fileAssociationSection);

    void setIsNewExtension(bool isNewExtension) { mIsNewExtension = isNewExtension; }
    void setExtension(QString extension);
    void setEditor(Editor *editor);
    bool isNewExtension() const { return mIsNewExtension; }

public slots:
    void accept();

private:
    void loadEditors();
    bool validate();
    bool existExtension();

    bool mIsNewExtension;
    SettingFileAssociationSection *mFileAssociationSection;


};
}

#endif // SettingSectionExtensionItem_h
