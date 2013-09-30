/********************************************************************************
** Form generated from reading UI file 'NewProjectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTDIALOG_H
#define UI_NEWPROJECTDIALOG_H

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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NewProjectDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLabel *labelProjectName;
    QLineEdit *location;
    QPushButton *browseLocation;
    QLabel *labelLocation;
    QLineEdit *projectName;

    void setupUi(QDialog *NewProjectDialog)
    {
        if (NewProjectDialog->objectName().isEmpty())
            NewProjectDialog->setObjectName(QStringLiteral("NewProjectDialog"));
        NewProjectDialog->resize(411, 137);
        NewProjectDialog->setSizeGripEnabled(false);
        NewProjectDialog->setModal(false);
        gridLayout = new QGridLayout(NewProjectDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(NewProjectDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 0, 1, 4);

        labelProjectName = new QLabel(NewProjectDialog);
        labelProjectName->setObjectName(QStringLiteral("labelProjectName"));

        gridLayout->addWidget(labelProjectName, 0, 0, 1, 1);

        location = new QLineEdit(NewProjectDialog);
        location->setObjectName(QStringLiteral("location"));

        gridLayout->addWidget(location, 4, 1, 1, 1);

        browseLocation = new QPushButton(NewProjectDialog);
        browseLocation->setObjectName(QStringLiteral("browseLocation"));

        gridLayout->addWidget(browseLocation, 4, 2, 1, 1);

        labelLocation = new QLabel(NewProjectDialog);
        labelLocation->setObjectName(QStringLiteral("labelLocation"));

        gridLayout->addWidget(labelLocation, 4, 0, 1, 1);

        projectName = new QLineEdit(NewProjectDialog);
        projectName->setObjectName(QStringLiteral("projectName"));

        gridLayout->addWidget(projectName, 0, 1, 1, 2);


        retranslateUi(NewProjectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewProjectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewProjectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *NewProjectDialog)
    {
        NewProjectDialog->setWindowTitle(QApplication::translate("NewProjectDialog", "New PHP project", 0));
        labelProjectName->setText(QApplication::translate("NewProjectDialog", "Project name", 0));
        browseLocation->setText(QApplication::translate("NewProjectDialog", "Browse..", 0));
        labelLocation->setText(QApplication::translate("NewProjectDialog", "Location", 0));
    } // retranslateUi

};

namespace Ui {
    class NewProjectDialog: public Ui_NewProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTDIALOG_H
