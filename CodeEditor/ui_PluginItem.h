/********************************************************************************
** Form generated from reading UI file 'PluginItem.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUGINITEM_H
#define UI_PLUGINITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PluginItem
{
public:
    QGridLayout *gridLayout;
    QPushButton *enable;
    QLabel *name;
    QPushButton *disableButton;
    QPushButton *deleteButton;
    QLabel *moreInfos;
    QLabel *description;

    void setupUi(QWidget *PluginItem)
    {
        if (PluginItem->objectName().isEmpty())
            PluginItem->setObjectName(QStringLiteral("PluginItem"));
        PluginItem->resize(551, 74);
        gridLayout = new QGridLayout(PluginItem);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        enable = new QPushButton(PluginItem);
        enable->setObjectName(QStringLiteral("enable"));

        gridLayout->addWidget(enable, 0, 3, 1, 1);

        name = new QLabel(PluginItem);
        name->setObjectName(QStringLiteral("name"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        name->setFont(font);

        gridLayout->addWidget(name, 0, 0, 1, 1);

        disableButton = new QPushButton(PluginItem);
        disableButton->setObjectName(QStringLiteral("disableButton"));

        gridLayout->addWidget(disableButton, 0, 2, 1, 1);

        deleteButton = new QPushButton(PluginItem);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        gridLayout->addWidget(deleteButton, 0, 1, 1, 1);

        moreInfos = new QLabel(PluginItem);
        moreInfos->setObjectName(QStringLiteral("moreInfos"));
        moreInfos->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(moreInfos, 1, 3, 1, 1);

        description = new QLabel(PluginItem);
        description->setObjectName(QStringLiteral("description"));

        gridLayout->addWidget(description, 1, 0, 1, 3);


        retranslateUi(PluginItem);

        QMetaObject::connectSlotsByName(PluginItem);
    } // setupUi

    void retranslateUi(QWidget *PluginItem)
    {
        PluginItem->setWindowTitle(QApplication::translate("PluginItem", "Form", 0));
        enable->setText(QApplication::translate("PluginItem", "Enable", 0));
        name->setText(QApplication::translate("PluginItem", "Plugin name", 0));
        disableButton->setText(QApplication::translate("PluginItem", "Disable", 0));
        deleteButton->setText(QApplication::translate("PluginItem", "Delete", 0));
        moreInfos->setText(QApplication::translate("PluginItem", "<html><head/><body><p align=\"right\">More infos</p></body></html>", 0));
        description->setText(QApplication::translate("PluginItem", "Description", 0));
    } // retranslateUi

};

namespace Ui {
    class PluginItem: public Ui_PluginItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINITEM_H
