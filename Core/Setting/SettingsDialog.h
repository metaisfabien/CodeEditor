#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include "ui_SettingsDialog.h"

#include <QDialog>

namespace PHPEditor {
class SettingsDialog : public QDialog, public Ui::SettingsDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();
};
}
#endif // SETTINGSDIALOG_H
