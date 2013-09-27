#ifndef PLUGINITEM_H
#define PLUGINITEM_H

#include <QWidget>

namespace Ui {
class PluginItem;
}

class PluginItem : public QWidget
{
    Q_OBJECT

public:
    explicit PluginItem(QWidget *parent = 0);
    ~PluginItem();

private:
    Ui::PluginItem *ui;
};

#endif // PLUGINITEM_H
