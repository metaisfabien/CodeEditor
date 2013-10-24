#include "Setting/Section/FileAssociation.h"
#include "Setting/Section/FileAssociation/ExtensionItem.h"
#include "Setting/Section/FileAssociation/ExtensionDialog.h"
#include "Setting/SettingsDialog.h"

#include "CodeEditor.h"
#include "Editor/Editor.h"
#include "Editor/EditorManager.h"
#include "Setting/SettingManager.h"
#include "Theme/ThemeManager.h"


#include <QTreeWidget>
#include <QSettings>
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
//    if (mExtensionDialog) delete mExtensionDialog;
}

void SettingFileAssociationSection::setupUi(QWidget *widget)
{
    mExtensionDialog = 0;
    Ui::SettingFileAssociationSection::setupUi(widget);

    loadExtensions();
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
    connect(edit, SIGNAL(clicked()), this,SLOT(editCurrentExtension()));
    connect(remove, SIGNAL(clicked()), this,SLOT(removeCurrentExtension()));
    connect(extensionsTree, SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)), this, SLOT(onCurrentExtensionChange(QTreeWidgetItem*,QTreeWidgetItem*)));
    connect(mSettingsDialog, SIGNAL(updateSettings()), this , SLOT(updateSettings()));
}

void SettingFileAssociationSection::loadExtensions()
{
    QSettings *settings = CodeEditor::getSettingManager()->getSettings();
    settings->beginGroup("file_association");

    foreach (const QString &key, settings->childKeys()) {
        qDebug() << "setting " + QString(key);
        qDebug() << settings->value(key).toString();
        QString EditorId = settings->value(key).toString();
        Editor *editor = CodeEditor::getEditorManager()->getEditorById(EditorId);
        if (editor) {
            addExtensionItem(key, editor);
        }
    }

    settings->endGroup();
}

void SettingFileAssociationSection::updateSettings()
{

    QSettings *settings = CodeEditor::getSettingManager()->getSettings();
    settings->beginGroup("file_association");

    QTreeWidgetItemIterator it(extensionsTree);
    while (*it) {
        SettingFileAssociationExtensionItem *item = dynamic_cast<SettingFileAssociationExtensionItem*>(*it);
        settings->setValue(item->getExtension(), item->getEditor()->getId());
        ++it;
    }
    settings->endGroup();
}

void SettingFileAssociationSection::addNewExtension()
{
    mExtensionDialog = new SettingFileAssociationExtensionDialog(mSettingsDialog, this);
    mExtensionDialog->setIsNewExtension(true);
    mExtensionDialog->show();
}

SettingFileAssociationExtensionItem *SettingFileAssociationSection::addExtensionItem(QString extension, Editor *editor)
{
    SettingFileAssociationExtensionItem *item = new SettingFileAssociationExtensionItem(extensionsTree);
    item->setExtension(extension);
    item->setEditor(editor);
    return item;
}

void SettingFileAssociationSection::onCurrentExtensionChange(QTreeWidgetItem* current,QTreeWidgetItem* last)
{
    if (current) {
        remove->setEnabled(true);
        edit->setEnabled(true);
    }
}

void SettingFileAssociationSection::editCurrentExtension()
{
    QTreeWidgetItem *current = extensionsTree->currentItem();
    SettingFileAssociationExtensionItem *item = dynamic_cast<SettingFileAssociationExtensionItem*>(current);

    mExtensionDialog = new SettingFileAssociationExtensionDialog(mSettingsDialog, this);
    mExtensionDialog->setEditor(item->getEditor());
    mExtensionDialog->setExtension(item->getExtension());
    mExtensionDialog->show();
}

void SettingFileAssociationSection::removeCurrentExtension()
{
   QTreeWidgetItem *item = extensionsTree->currentItem();
   delete item;
}

void SettingFileAssociationSection::updateCurrentExtension(QString extension, Editor *editor)
{
    QTreeWidgetItem *current = extensionsTree->currentItem();
    SettingFileAssociationExtensionItem *item = dynamic_cast<SettingFileAssociationExtensionItem*>(current);
    item->setExtension(extension);
    item->setEditor(editor);
}


}


