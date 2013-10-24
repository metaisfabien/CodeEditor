#include "PluginsDialog.h"
#include "ui_PluginsDialog.h"
#include "CodeEditor.h"
#include "Plugin/PluginManager.h"
#include "Plugin/PluginData.h"
#include "Plugin/PluginItem.h"

#include <map>

#include "QDebug"

using namespace std;
namespace CE {
PluginsDialog::PluginsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::PluginsDialog)
{
    ui->setupUi(this);

    QHashIterator<QString, PluginData*> pluginDataIterator(CodeEditor::getPluginManager()->getPluginsData());
    while (pluginDataIterator.hasNext()) {
        pluginDataIterator.next();
        PluginItem *pluginItem = new PluginItem(pluginDataIterator.value(), this);
        QListWidgetItem* item = new QListWidgetItem(ui->pluginsList);
        item->setSizeHint(pluginItem->sizeHint());
        ui->pluginsList->addItem(item);
        ui->pluginsList->setItemWidget(item, pluginItem);
        pluginItem->show();
    }
}

PluginsDialog::~PluginsDialog()
{
    delete ui;
}
}

