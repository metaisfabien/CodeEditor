#ifndef SETTINGFILEASSOCIATIONSECTION_H
#define SETTINGFILEASSOCIATIONSECTION_H
#include "ui_SettingFileAssociationSection.h"
#include "Setting/SettingsDialogSection.h"

#include <QString>

QT_BEGIN_NAMESPACE
class QTreeWidget;
class QTreeWidgetItem;
QT_END_NAMESPACE

namespace CE {
class Editor;
class SettingsDialog;
class SettingFileAssociationExtensionItem;
class SettingFileAssociationExtensionDialog;

class SettingFileAssociationSection : public SettingsDialogSection , public Ui::SettingFileAssociationSection
{
    Q_OBJECT
public:
    SettingFileAssociationSection(QString id, QTreeWidget *parent, SettingsDialog *settingsDialog);
    SettingFileAssociationSection(QString id, SettingsDialogSection *parent, SettingsDialog *settingsDialog);

    ~SettingFileAssociationSection();

    void setupUi(QWidget *widget);

    SettingFileAssociationExtensionItem *addExtensionItem(QString extension = QString::null, Editor *editor = 0);
    void updateCurrentExtension(QString extension, Editor *editor);


public slots:
    void addNewExtension();
    void onCurrentExtensionChange(QTreeWidgetItem* current,QTreeWidgetItem* last);
    void removeCurrentExtension();
    void editCurrentExtension();
    void updateSettings();

private:
    void loadExtensions();

    SettingFileAssociationExtensionDialog *mExtensionDialog;
};
}
#endif // SETTINGFILEASSOCIATIONSECTION_H
