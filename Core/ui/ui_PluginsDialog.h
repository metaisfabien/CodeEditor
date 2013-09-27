/********************************************************************************
** Form generated from reading UI file 'PluginsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUGINSDIALOG_H
#define UI_PLUGINSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_PluginsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *PluginsDialog)
    {
        if (PluginsDialog->objectName().isEmpty())
            PluginsDialog->setObjectName(QStringLiteral("PluginsDialog"));
        PluginsDialog->resize(569, 345);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PluginsDialog->sizePolicy().hasHeightForWidth());
        PluginsDialog->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(PluginsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(300, 310, 241, 23));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(PluginsDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(19, 35, 531, 251));
        lineEdit = new QLineEdit(PluginsDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(420, 10, 133, 20));
        label = new QLabel(PluginsDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 10, 31, 20));

        retranslateUi(PluginsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PluginsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PluginsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PluginsDialog);
    } // setupUi

    void retranslateUi(QDialog *PluginsDialog)
    {
        PluginsDialog->setWindowTitle(QApplication::translate("PluginsDialog", "Dialog", 0));
        label->setText(QApplication::translate("PluginsDialog", "Filter", 0));
    } // retranslateUi

};

namespace Ui {
    class PluginsDialog: public Ui_PluginsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINSDIALOG_H
