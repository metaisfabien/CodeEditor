#include "Setting/Section/SettingFileAssociationSection.h"
#include "Setting/Section/ExtensionItem.h"
#include "Setting/Section/ExtensionDialog.h"
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

}

void SettingFileAssociationSection::setupUi(QWidget *widget)
{
    mExtensionDialog = 0;
    Ui::SettingFileAssociationSection::setupUi(widget);

    //QSettings *settings = CodeEditor::getSettingManager()->getSettings();
    //showLineNumber->setChecked(settings->value("editors/show_line_number").toBool());

    addExtension->setIcon(QIcon(CodeEditor::getThemeManager()->getIcon("add")));
    addExtension->setIconSize(QSize(20,20));
    addExtension->setText("");
    addExtension->setFlat(true);
    addExtension->setFocusPolicy(Qt::NoFocus);
    addExtension->setStyleSheet("QPushButton:flat:pressed { border: none; };");

    removeExtension->setIcon(QIcon(CodeEditor::getThemeManager()->getIcon("remove")));
    removeExtension->setIconSize(QSize(20,20));
    removeExtension->setText("");
    removeExtension->setFlat(true);
    removeExtension->setFocusPolicy(Qt::NoFocus);
    removeExtension->setStyleSheet("QPushButton:flat:pressed { border: none; };");
    removeExtension->setEnabled(false);

    extensionLineEdit->setEnabled(false);
    editor->setEnabled(false);
/*
    map<QString, Editor*>::iterator editorIterator;
    map<QString, Editor*> editors = CodeEditor::getEditorManager()->getEditors();
    for(editorIterator = editors.begin(); editorIterator != editors.end(); ++editorIterator) {

        QListWidgetItem *item = new QListWidgetItem(editorsList);
        item->setText((editorIterator->second)->getName());
        editorsList->addItem(item);
    }
*/

    connect(addExtension, SIGNAL(clicked()), this, SLOT(addNewExtension()));
    connect(removeExtension, SIGNAL(clicked()), this,SLOT(removeCurrentExtension()));
    connect(extensionsList, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)), this, SLOT(onCurrentExtensionChange(QListWidgetItem*,QListWidgetItem*)));
    connect(extensionLineEdit, SIGNAL(textChanged(QString)), this, SLOT(updateCurrentExtensionText(QString)));

}

void SettingFileAssociationSection::addNewExtension()
{
    if (!mExtensionDialog) {
        mExtensionDialog = new ExtensionDialog(mSettingsDialog);
    }
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

ExtensionItem *SettingFileAssociationSection::addExtensionItem(QString extension, Editor *editor)
{
    ExtensionItem *item = new ExtensionItem(extension, editor);

    item->setSizeHint(item->getWidget()->sizeHint());
    extensionsList->addItem(item);
    extensionsList->setItemWidget(item, item->getWidget());
    item->getWidget()->show();
    return item;
}

void SettingFileAssociationSection::onCurrentExtensionChange(QListWidgetItem* current,QListWidgetItem* last)
{
    if (current) {
        ExtensionItem *item = dynamic_cast<ExtensionItem*>(current);
        removeExtension->setEnabled(true);
        extensionLineEdit->setEnabled(true);
        editor->setEnabled(true);
        extensionLineEdit->setText(item->getExtension());

    }
}

void SettingFileAssociationSection::removeCurrentExtension()
{
   QListWidgetItem *item = extensionsList->currentItem();
   delete item;
}

void SettingFileAssociationSection::updateCurrentExtensionText(QString text)
{
  //  QModelIndex index = extensionsList->currentIndex();
    QListWidgetItem *currentItem = extensionsList->currentItem();
    ExtensionItem *item = dynamic_cast<ExtensionItem*>(currentItem);
    //ExtensionItem *item = ((ExtensionItem *)currentItem);
    item->getExtensionLabel()->setText(text);
}

}


