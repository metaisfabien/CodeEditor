/********************************************************************************
** Form generated from reading UI file 'SettingEditorsSection.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGEDITORSSECTION_H
#define UI_SETTINGEDITORSSECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingEditorsSection
{
public:
    QGridLayout *gridLayout;
    QCheckBox *highlightCurrentLine;
    QCheckBox *showLineNumber;
    QSpacerItem *verticalSpacer;
    QCheckBox *insertSpaceForTable;

    void setupUi(QWidget *SettingEditorsSection)
    {
        if (SettingEditorsSection->objectName().isEmpty())
            SettingEditorsSection->setObjectName(QStringLiteral("SettingEditorsSection"));
        SettingEditorsSection->resize(533, 402);
        gridLayout = new QGridLayout(SettingEditorsSection);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        highlightCurrentLine = new QCheckBox(SettingEditorsSection);
        highlightCurrentLine->setObjectName(QStringLiteral("highlightCurrentLine"));
        QFont font;
        font.setPointSize(10);
        highlightCurrentLine->setFont(font);

        gridLayout->addWidget(highlightCurrentLine, 1, 0, 1, 1);

        showLineNumber = new QCheckBox(SettingEditorsSection);
        showLineNumber->setObjectName(QStringLiteral("showLineNumber"));
        showLineNumber->setFont(font);

        gridLayout->addWidget(showLineNumber, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        insertSpaceForTable = new QCheckBox(SettingEditorsSection);
        insertSpaceForTable->setObjectName(QStringLiteral("insertSpaceForTable"));
        insertSpaceForTable->setFont(font);

        gridLayout->addWidget(insertSpaceForTable, 2, 0, 1, 1);


        retranslateUi(SettingEditorsSection);

        QMetaObject::connectSlotsByName(SettingEditorsSection);
    } // setupUi

    void retranslateUi(QWidget *SettingEditorsSection)
    {
        SettingEditorsSection->setWindowTitle(QApplication::translate("SettingEditorsSection", "Form", 0));
        highlightCurrentLine->setText(QApplication::translate("SettingEditorsSection", "Highlight current line", 0));
        showLineNumber->setText(QApplication::translate("SettingEditorsSection", "Show line number", 0));
        insertSpaceForTable->setText(QApplication::translate("SettingEditorsSection", "Insert space for table", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingEditorsSection: public Ui_SettingEditorsSection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGEDITORSSECTION_H
