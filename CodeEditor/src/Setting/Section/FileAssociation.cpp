#include "Setting/Section/FileAssociation.h"
#include "Setting/Section/FileAssociation/ExtensionItem.h"
#include "Setting/Section/FileAssociation/ExtensionDialog.h"
#include "Setting/SettingsDialog.h"

#include "CodeEditor.h"
#include "Editor/Editor.h"
#include "Editor/EditorManager.h"
#include "Theme/ThemeManager.h"


#include <QTreeWidget>
#include <QDebug>
#include <QObject>

namespace CE {

SettingFileAssociationSection::SettingFileAssociationSection(QString id, QTreeWidget *parent, SettingsDialog *settingsDialog)
    : SettingsDialogSection(id, parent, settingsDialog)
{
    setupUi(this);
}

SettingFileAssociationSection::SettingFileAssociationSection(QString id, SettingsDialogSection *parent, SettingsDialog *settingsDialog)
    : SettingsDialogSection(id, parent, settingsDialog)
{
    setupUi(this);
}

SettingFileAssociationSection::~SettingFileAssociationSection()
{
    if (mExtensionDialog) delete mExtensionDialog;
}

void SettingFileAssociationSection::setupUi(QWidget *widget)
{
    mExtensionDialog = 0;
    Ui::SettingFileAssociationSection::setupUi(widget);

    //QSettings *settings = CodeEditor::getSettingManager()->getSettings();
    //showLineNumber->setChecked(settings->value("editors/show_line_number").toBool());

    add->setIcon(QIcon(CodeEditor::getThemeManager()->getIcon("add")));
    add->setIconSize(QSize(20,20));
    add->setText("");
    add->setFlat(true);
    add->setFocusPolicy(Qt::NoFocus);
    add->setStyleSheet("QPushButton:flat:pressed { border: none; };");

    remove->setIcon(QIcon(CodeEditor::getThemeManager()->getIcon("remove")));
    remove->setIconSize(QSize(20,20));
    remove->setText("");
    remove->setFlat(true);
    remove->setFocusPolicy(Qt::NoFocus);
    remove->setStyleSheet("QPushButton:flat:pressed { border: none; };");
    remove->setEnabled(false);

    edit->setIcon(QIcon(CodeEditor::getThemeManager()->getIcon("edit")));
    edit->setIconSize(QSize(20,20));
    edit->setText("");
    edit->setFlat(true);
    edit->setFocusPolicy(Qt::NoFocus);
    edit->setStyleSheet("QPushButton:flat:pressed { border: none; };");
    edit->setEnabled(false);


    connect(add, SIGNAL(clicked()), this, SLOT(addNewExtension()));
    connect(remove, SIGNAL(clicked()), this,SLOT(removeCurrentExtension()));
    connect(extensionsList, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(onCurrentExtensionChange(QListWidgetItem*,QListWidgetItem*)));
}

void SettingFileAssociationSection::addNewExtension()
{
    mExtensionDialog = new SettingFileAssociationExtensionDialog(mSettingsDialog);
    mExtensionDialog->show();
    /**
    ExtensionItem *item = 0;
    if(extensionsList->count() != 0) {
        QListWidgetItem *lastItem = extensionsList->item(extensionsList->count());
        if (lastItem) {
            item = dynamic_cast<ExtensionItem*>(lastItem);
            if (item->getExtension() != "") {
                item = addExtensionItem();
            }
        } else {
            item = addExtensionItem();
        }
    } else {
        item = addExtensionItem();
    }
    extensionsList->setCurrentItem(item);
    extensionLineEdit->setFocus();
    **/
}

SettingFileAssociationExtensionItem *SettingFileAssociationSection::addExtensionItem(QString extension, Editor *editor)
{
    SettingFileAssociationExtensionItem *item = new SettingFileAssociationExtensionItem(extension, editor);

    item->setSizeHint(item->getWidget()->sizeHint());
    extensionsList->addItem(item);
    extensionsList->setItemWidget(item, item->getWidget());
    item->getWidget()->show();
    return item;
}

void SettingFileAssociationSection::onCurrentExtensionChange(QListWidgetItem* current,QListWidgetItem* last)
{
    if (current) {
        //SettingFileAssociationExtensionItem *item = dynamic_cast<SettingFileAssociationExtensionItem*>(current);
        remove->setEnabled(true);
    }
}

void SettingFileAssociationSection::removeCurrentExtension()
{
   QListWidgetItem *item = extensionsList->currentItem();
   delete item;
}

}


