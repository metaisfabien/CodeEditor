#include "PluginItem.h"
#include "ui_PluginItem.h"

PluginItem::PluginItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PluginItem)
{
    ui->setupUi(this);
}

PluginItem::~PluginItem()
{
    delete ui;
}
