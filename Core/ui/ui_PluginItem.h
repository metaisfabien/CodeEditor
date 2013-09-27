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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PluginItem
{
public:
    QLabel *name;
    QLabel *description;
    QPushButton *enable;
    QPushButton *disableButton;
    QPushButton *deleteButton;
    QLabel *moreInfos;

    void setupUi(QWidget *PluginItem)
    {
        if (PluginItem->objectName().isEmpty())
            PluginItem->setObjectName(QStringLiteral("PluginItem"));
        PluginItem->resize(551, 68);
        name = new QLabel(PluginItem);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(10, 10, 181, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        name->setFont(font);
        description = new QLabel(PluginItem);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(10, 40, 231, 16));
        enable = new QPushButton(PluginItem);
        enable->setObjectName(QStringLiteral("enable"));
        enable->setGeometry(QRect(470, 10, 75, 23));
        disableButton = new QPushButton(PluginItem);
        disableButton->setObjectName(QStringLiteral("disableButton"));
        disableButton->setGeometry(QRect(470, 10, 75, 23));
        deleteButton = new QPushButton(PluginItem);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(390, 10, 75, 23));
        moreInfos = new QLabel(PluginItem);
        moreInfos->setObjectName(QStringLiteral("moreInfos"));
        moreInfos->setGeometry(QRect(490, 40, 61, 20));
        moreInfos->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(PluginItem);

        QMetaObject::connectSlotsByName(PluginItem);
    } // setupUi

    void retranslateUi(QWidget *PluginItem)
    {
        PluginItem->setWindowTitle(QApplication::translate("PluginItem", "Form", 0));
        name->setText(QApplication::translate("PluginItem", "Plugin name", 0));
        description->setText(QApplication::translate("PluginItem", "Description", 0));
        enable->setText(QApplication::translate("PluginItem", "Enable", 0));
        disableButton->setText(QApplication::translate("PluginItem", "Disable", 0));
        deleteButton->setText(QApplication::translate("PluginItem", "Delete", 0));
        moreInfos->setText(QApplication::translate("PluginItem", "More infos", 0));
    } // retranslateUi

};

namespace Ui {
    class PluginItem: public Ui_PluginItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINITEM_H
