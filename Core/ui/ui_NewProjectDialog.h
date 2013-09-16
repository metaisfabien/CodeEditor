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
    QLabel *label_project_name;
    QLineEdit *lineEdit;
    QPushButton *browse_location;
    QLabel *label_location;
    QLineEdit *project_name;

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

        label_project_name = new QLabel(NewProjectDialog);
        label_project_name->setObjectName(QStringLiteral("label_project_name"));

        gridLayout->addWidget(label_project_name, 0, 0, 1, 1);

        lineEdit = new QLineEdit(NewProjectDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 4, 1, 1, 1);

        browse_location = new QPushButton(NewProjectDialog);
        browse_location->setObjectName(QStringLiteral("browse_location"));

        gridLayout->addWidget(browse_location, 4, 2, 1, 1);

        label_location = new QLabel(NewProjectDialog);
        label_location->setObjectName(QStringLiteral("label_location"));

        gridLayout->addWidget(label_location, 4, 0, 1, 1);

        project_name = new QLineEdit(NewProjectDialog);
        project_name->setObjectName(QStringLiteral("project_name"));

        gridLayout->addWidget(project_name, 0, 1, 1, 2);


        retranslateUi(NewProjectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewProjectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewProjectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *NewProjectDialog)
    {
        NewProjectDialog->setWindowTitle(QApplication::translate("NewProjectDialog", "New PHP project", 0));
        label_project_name->setText(QApplication::translate("NewProjectDialog", "Project name", 0));
        browse_location->setText(QApplication::translate("NewProjectDialog", "Browse..", 0));
        label_location->setText(QApplication::translate("NewProjectDialog", "Location", 0));
    } // retranslateUi

};

namespace Ui {
    class NewProjectDialog: public Ui_NewProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTDIALOG_H
