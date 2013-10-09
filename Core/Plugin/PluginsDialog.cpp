#include "PluginsDialog.h"
#include "ui_PluginsDialog.h"
#include "Core.h"
#include "Plugin/PluginManager.h"
#include "Plugin/PluginData.h"
#include "Plugin/PluginItem.h"

#include <map>

#include "QDebug"

using namespace std;
namespace PHPEditor {
PluginsDialog::PluginsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::PluginsDialog)
{
    ui->setupUi(this);
    map<QString, PluginData*> pluginsData = Core::getPluginManager()->getPluginsData();

    map<QString, PluginData*>::iterator pluginDataIterator;
    for(pluginDataIterator = pluginsData.begin(); pluginDataIterator != pluginsData.end(); ++pluginDataIterator) {
        PluginData *pluginData = pluginDataIterator->second;
        PluginItem *pluginItem = new PluginItem(pluginData, this);
        QListWidgetItem* item = new QListWidgetItem(ui->pluginsList);
        item->setSizeHint(pluginItem->sizeHint());
        ui->pluginsList->addItem(item);
        ui->pluginsList->setItemWidget(item, pluginItem);
        pluginItem->show();
        qDebug() << "add plugin to list" << pluginItem->sizeHint();
    }
}

PluginsDialog::~PluginsDialog()
{
    delete ui;
}
}

