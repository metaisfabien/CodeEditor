#include "Setting/Section/FileAssociation/ExtensionDialog.h"
#include "Setting/Section/FileAssociation.h"

#include "CodeEditor.h"
#include "Editor/EditorManager.h"
#include "Editor/Editor.h"

#include <QListWidgetItem>
#include <QDebug>

namespace CE{
SettingFileAssociationExtensionDialog::SettingFileAssociationExtensionDialog(QWidget *parent, SettingFileAssociationSection* fileAssociationSection) :
    QDialog(parent)
{
    setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    loadEditors();
    mIsNewExtension = false;
    mFileAssociationSection = fileAssociationSection;
}

void SettingFileAssociationExtensionDialog::setExtension(QString extension)
{
    extensionLineEdit->setText(extension);
}

void SettingFileAssociationExtensionDialog::setEditor(Editor *editor)
{
    int index = editorsComboBox->findData(editor->getId());
    if (index != -1) {
        editorsComboBox->setCurrentIndex(index);
    }
}

void SettingFileAssociationExtensionDialog::loadEditors()
{
    map<QString, Editor*>::iterator editorIterator;
    map<QString, Editor*> editors = CodeEditor::getEditorManager()->getEditors();
    for(editorIterator = editors.begin(); editorIterator != editors.end(); ++editorIterator) {
        editorsComboBox->addItem((editorIterator->second)->getName(), (editorIterator->second)->getId());
    }
}

void SettingFileAssociationExtensionDialog::accept()
{

    if (validate()) {
        QString editorId = editorsComboBox->itemData(editorsComboBox->currentIndex()).toString();
        Editor * editor = CodeEditor::getEditorManager()->getEditorById(editorId);
        if (isNewExtension()) {
            mFileAssociationSection->addExtensionItem(extensionLineEdit->text(), editor);
        } else {
            mFileAssociationSection->updateCurrentExtension(extensionLineEdit->text(), editor);
        }
        QDialog::accept();
    }

}

bool SettingFileAssociationExtensionDialog::validate()
{
    //remove all error
    QLayoutItem* item;
    while ((item = errorsLayout->takeAt(0)) != NULL){
        delete item->widget();
        delete item;
    }


    if (extensionLineEdit->text() == "") {
        QLabel *errorLabel = new QLabel("Please enter an extension");
        QFont font;
        font.setPointSize(10);
        errorLabel->setFont(font);
        errorsLayout->addWidget(errorLabel);
        return false;
    } else if (existExtension()) {
        QLabel *errorLabel = new QLabel("This extension already exist");
        QFont font;
        font.setPointSize(10);
        errorLabel->setFont(font);
        errorsLayout->addWidget(errorLabel);
    }


    return true;
}

bool SettingFileAssociationExtensionDialog::existExtension()
{
    int numExtension = 0;
    //mFileAssociationSection->extensionsList
    return false;
}

}

