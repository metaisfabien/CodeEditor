/********************************************************************************
** Form generated from reading UI file 'SettingFileAssociationExtensionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGFILEASSOCIATIONEXTENSIONDIALOG_H
#define UI_SETTINGFILEASSOCIATIONEXTENSIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SettingFileAssociationExtensionDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLineEdit *extensionLineEdit;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QLabel *extensionErrorLabel;

    void setupUi(QDialog *SettingFileAssociationExtensionDialog)
    {
        if (SettingFileAssociationExtensionDialog->objectName().isEmpty())
            SettingFileAssociationExtensionDialog->setObjectName(QStringLiteral("SettingFileAssociationExtensionDialog"));
        SettingFileAssociationExtensionDialog->resize(400, 105);
        SettingFileAssociationExtensionDialog->setModal(true);
        gridLayout = new QGridLayout(SettingFileAssociationExtensionDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        extensionLineEdit = new QLineEdit(SettingFileAssociationExtensionDialog);
        extensionLineEdit->setObjectName(QStringLiteral("extensionLineEdit"));

        gridLayout->addWidget(extensionLineEdit, 0, 2, 1, 1);

        label = new QLabel(SettingFileAssociationExtensionDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SettingFileAssociationExtensionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 2, 1, 1);

        extensionErrorLabel = new QLabel(SettingFileAssociationExtensionDialog);
        extensionErrorLabel->setObjectName(QStringLiteral("extensionErrorLabel"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
        extensionErrorLabel->setPalette(palette);
        extensionErrorLabel->setFont(font);

        gridLayout->addWidget(extensionErrorLabel, 1, 2, 1, 1);


        retranslateUi(SettingFileAssociationExtensionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingFileAssociationExtensionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingFileAssociationExtensionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingFileAssociationExtensionDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingFileAssociationExtensionDialog)
    {
        SettingFileAssociationExtensionDialog->setWindowTitle(QApplication::translate("SettingFileAssociationExtensionDialog", "Dialog", 0));
        label->setText(QApplication::translate("SettingFileAssociationExtensionDialog", "Extension", 0));
        extensionErrorLabel->setText(QApplication::translate("SettingFileAssociationExtensionDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingFileAssociationExtensionDialog: public Ui_SettingFileAssociationExtensionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGFILEASSOCIATIONEXTENSIONDIALOG_H
