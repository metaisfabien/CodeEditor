#include "TestPlugin.h"
#include "Core.h"
#include "MainWindow.h"

#include <QDebug>
#include <QMenuBar>

using namespace PHPEditor;

TestPlugin::TestPlugin()
{
    id = "test_plugin";
}

bool TestPlugin::load()
{
    qDebug() << "load plugin TestPlugin";
    QAction *action = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/arrow_up_blue.png"), tr("&Test Action"), this);

    action->setStatusTip(tr("Test Action"));
    MainWindow *mainWindow = Core::getMainWindow();

    QMenu *menu = mainWindow->menuBar()->addMenu("Test plugin");
    menu->addAction(action);

    return true;
}

bool TestPlugin::unLoad()
{
    return true;
}

