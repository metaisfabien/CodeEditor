/********************************************************************************
** Form generated from reading UI file 'SettingFileAssociationSection.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGFILEASSOCIATIONSECTION_H
#define UI_SETTINGFILEASSOCIATIONSECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingFileAssociationSection
{
public:
    QGridLayout *gridLayout;
    QLineEdit *extensionLineEdit;
    QVBoxLayout *extensionsButtonsLayout;
    QPushButton *addExtension;
    QPushButton *removeExtension;
    QSpacerItem *verticalSpacer_3;
    QListWidget *extensionsList;
    QLabel *extensionLabel;
    QSpacerItem *verticalSpacer;
    QLabel *extensionsListLabel;
    QLabel *label;
    QComboBox *editor;

    void setupUi(QWidget *SettingFileAssociationSection)
    {
        if (SettingFileAssociationSection->objectName().isEmpty())
            SettingFileAssociationSection->setObjectName(QStringLiteral("SettingFileAssociationSection"));
        SettingFileAssociationSection->resize(442, 302);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingFileAssociationSection->sizePolicy().hasHeightForWidth());
        SettingFileAssociationSection->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(SettingFileAssociationSection);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        extensionLineEdit = new QLineEdit(SettingFileAssociationSection);
        extensionLineEdit->setObjectName(QStringLiteral("extensionLineEdit"));

        gridLayout->addWidget(extensionLineEdit, 3, 0, 1, 1);

        extensionsButtonsLayout = new QVBoxLayout();
        extensionsButtonsLayout->setObjectName(QStringLiteral("extensionsButtonsLayout"));
        addExtension = new QPushButton(SettingFileAssociationSection);
        addExtension->setObjectName(QStringLiteral("addExtension"));

        extensionsButtonsLayout->addWidget(addExtension);

        removeExtension = new QPushButton(SettingFileAssociationSection);
        removeExtension->setObjectName(QStringLiteral("removeExtension"));

        extensionsButtonsLayout->addWidget(removeExtension);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        extensionsButtonsLayout->addItem(verticalSpacer_3);


        gridLayout->addLayout(extensionsButtonsLayout, 1, 1, 1, 1);

        extensionsList = new QListWidget(SettingFileAssociationSection);
        extensionsList->setObjectName(QStringLiteral("extensionsList"));

        gridLayout->addWidget(extensionsList, 1, 0, 1, 1);

        extensionLabel = new QLabel(SettingFileAssociationSection);
        extensionLabel->setObjectName(QStringLiteral("extensionLabel"));
        QFont font;
        font.setPointSize(10);
        extensionLabel->setFont(font);

        gridLayout->addWidget(extensionLabel, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        extensionsListLabel = new QLabel(SettingFileAssociationSection);
        extensionsListLabel->setObjectName(QStringLiteral("extensionsListLabel"));
        extensionsListLabel->setFont(font);

        gridLayout->addWidget(extensionsListLabel, 0, 0, 1, 1);

        label = new QLabel(SettingFileAssociationSection);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 4, 0, 1, 1);

        editor = new QComboBox(SettingFileAssociationSection);
        editor->setObjectName(QStringLiteral("editor"));

        gridLayout->addWidget(editor, 5, 0, 1, 1);


        retranslateUi(SettingFileAssociationSection);

        QMetaObject::connectSlotsByName(SettingFileAssociationSection);
    } // setupUi

    void retranslateUi(QWidget *SettingFileAssociationSection)
    {
        SettingFileAssociationSection->setWindowTitle(QApplication::translate("SettingFileAssociationSection", "Form", 0));
        addExtension->setText(QApplication::translate("SettingFileAssociationSection", "Add...", 0));
        removeExtension->setText(QApplication::translate("SettingFileAssociationSection", "Remove", 0));
        extensionLabel->setText(QApplication::translate("SettingFileAssociationSection", "Extension:", 0));
        extensionsListLabel->setText(QApplication::translate("SettingFileAssociationSection", "Extensions:", 0));
        label->setText(QApplication::translate("SettingFileAssociationSection", "Editor:", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingFileAssociationSection: public Ui_SettingFileAssociationSection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGFILEASSOCIATIONSECTION_H
