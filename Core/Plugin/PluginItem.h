#ifndef PLUGINITEM_H
#define PLUGINITEM_H

#include <QWidget>
#include "ui_PluginItem.h"


namespace PHPEditor{
class PluginData;
class PluginItem : public QWidget, public Ui::PluginItem
{
    Q_OBJECT

public:
    explicit PluginItem(PluginData *pluginData, QWidget *parent = 0);
    ~PluginItem();

};
}

#endif // PLUGINITEM_H
