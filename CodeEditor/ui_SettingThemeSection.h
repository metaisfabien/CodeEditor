/********************************************************************************
** Form generated from reading UI file 'SettingThemeSection.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGTHEMESECTION_H
#define UI_SETTINGTHEMESECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingThemeSection
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QLabel *label;
    QComboBox *themeComboBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SettingThemeSection)
    {
        if (SettingThemeSection->objectName().isEmpty())
            SettingThemeSection->setObjectName(QStringLiteral("SettingThemeSection"));
        SettingThemeSection->resize(501, 396);
        gridLayout = new QGridLayout(SettingThemeSection);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableWidget = new QTableWidget(SettingThemeSection);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 1, 0, 1, 2);

        label = new QLabel(SettingThemeSection);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        themeComboBox = new QComboBox(SettingThemeSection);
        themeComboBox->setObjectName(QStringLiteral("themeComboBox"));

        gridLayout->addWidget(themeComboBox, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 349, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(SettingThemeSection);

        QMetaObject::connectSlotsByName(SettingThemeSection);
    } // setupUi

    void retranslateUi(QWidget *SettingThemeSection)
    {
        SettingThemeSection->setWindowTitle(QApplication::translate("SettingThemeSection", "Form", 0));
        label->setText(QApplication::translate("SettingThemeSection", "Theme", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingThemeSection: public Ui_SettingThemeSection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGTHEMESECTION_H
