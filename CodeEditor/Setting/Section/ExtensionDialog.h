#ifndef SettingSectionExtensionDialog_h
#define SettingSectionExtensionDialog_h


#include "ui_SettingFileAssociationExtensionDialog.h"

namespace CE{
namespace Setting{
namespace Section{
namespace FileAssociation {
class ExtensionDialog : public QDialog, public Ui::SettingFileAssociationExtensionDialog {
public:
    ExtensionDialog(QWidget *parent);
private:

};
}
}
}
}

#endif // SettingSectionExtensionItem_h
