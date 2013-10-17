/********************************************************************************
** Form generated from reading UI file 'SettingGeneralSection.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGGENERALSECTION_H
#define UI_SETTINGGENERALSECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingGeneralSection
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QLabel *label;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SettingGeneralSection)
    {
        if (SettingGeneralSection->objectName().isEmpty())
            SettingGeneralSection->setObjectName(QStringLiteral("SettingGeneralSection"));
        SettingGeneralSection->resize(514, 322);
        gridLayout = new QGridLayout(SettingGeneralSection);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox = new QComboBox(SettingGeneralSection);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 2, 1, 1);

        label = new QLabel(SettingGeneralSection);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 2, 1, 1);


        retranslateUi(SettingGeneralSection);

        QMetaObject::connectSlotsByName(SettingGeneralSection);
    } // setupUi

    void retranslateUi(QWidget *SettingGeneralSection)
    {
        SettingGeneralSection->setWindowTitle(QApplication::translate("SettingGeneralSection", "Form", 0));
        label->setText(QApplication::translate("SettingGeneralSection", "Language", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingGeneralSection: public Ui_SettingGeneralSection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGGENERALSECTION_H
