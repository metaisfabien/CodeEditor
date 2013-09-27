#include "PluginsDialog.h"
#include "ui_PluginsDialog.h"
#include "Core.h"
#include "Plugin/PluginManager.h"
#include "Plugin/PluginData.h"

#include <map>

using namespace std;
namespace PHPEditor {
PluginsDialog::PluginsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::PluginsDialog)
{
    ui->setupUi(this);
    map<QString, PluginData*> pluginsData = Core::getPluginManager()->getPluginsData();
}

PluginsDialog::~PluginsDialog()
{
    delete ui;
}
}
