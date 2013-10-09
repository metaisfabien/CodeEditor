#include "PluginItem.h"
#include "Plugin/PluginData.h"

namespace PHPEditor {
PluginItem::PluginItem(PluginData *pluginData, QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    name->setText(pluginData->getId());
}

PluginItem::~PluginItem()
{

}
}
