#include "MainWindow.h"
#include "Core.h"

#include "Plugin/PluginManager.h"
#include "Setting/SettingManager.h"

#include <QCoreApplication>
#include <QTabWidget>
#include <QMenu>
#include <QDir>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QTextBrowser>

#include <QDebug>

namespace PHPEditor {
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    createActions();
    createMenu();
    createMainToolBar();

    mTabWidget = new QTabWidget();

    setCentralWidget(mTabWidget);
}

MainWindow::~MainWindow()
{

    delete mPluginsAction;
    delete mSettingsAction;
    delete mToggleSearchAction;
    delete mSaveAction;
    delete mOpenFileAction,
    delete mNewFileAction;
    delete mTabWidget;
}

/**
 * Crée les actions du programme
 *
 * @brief MainWindow::createActions
 */
void MainWindow::createActions()
{
    //Nouveau
    mNewFileAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/new.png"), tr("&File"), this);
    mNewFileAction->setShortcuts(QKeySequence::New);
    mNewFileAction->setStatusTip(tr("file"));

    //Ouvrir fichier
    mOpenFileAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/open.png"), tr("&Open file"), this);
    mOpenFileAction->setShortcuts(QKeySequence::Open);
    mOpenFileAction->setStatusTip(tr("open file"));

    //Sauvegarder
    mSaveAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/save.png"), tr("&Save"), this);
    mSaveAction->setShortcuts(QKeySequence::Save);
    mSaveAction->setStatusTip(tr("save"));

    //Rechercher
    mToggleSearchAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/search.png"), tr("&Search"), this);
    mToggleSearchAction->setShortcuts(QKeySequence::Find);
    mToggleSearchAction->setStatusTip(tr("search"));

    mSettingsAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/setting.png"), tr("&Settings"), this);
    mSettingsAction->setStatusTip(tr("settings"));
    QObject::connect(mSettingsAction, SIGNAL(triggered()), Core::getSettingManager(), SLOT(showSettingsDialog()));


    mPluginsAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/setting.png"), tr("&Plugins"), this);
    mPluginsAction->setStatusTip(tr("Plugins"));
    QObject::connect(mPluginsAction, SIGNAL(triggered()), Core::getPluginManager(), SLOT(showPluginsDialog()));
}

/**
 * @brief MainWindow::createMenu
 *
 * Create the default main menu
 */
void MainWindow::createMenu()
{
    mFileMenu = menuBar()->addMenu(tr("&File"));

    mNewMenu = mFileMenu->addMenu(tr("&New"));
    mNewMenu->addAction(mNewFileAction);

    mFileMenu->addAction(mOpenFileAction);
    mFileMenu->addAction(mSaveAction);

    mToolsMenu = menuBar()->addMenu(tr("&Tools"));
    mToolsMenu->addAction(mSettingsAction);
    mToolsMenu->addAction(mPluginsAction);
}

/**
 * Crée le toolbar principal
 * @brief MainWindow::createMainToolBar
 */
void MainWindow::createMainToolBar()
{
    //creation de la toolbar
    mMainToolBar = new QToolBar;
    addToolBar(Qt::TopToolBarArea, mMainToolBar);

    //Nouveau fichier
    mMainToolBar->addAction(mNewFileAction);

    //Ouvrir fichier
    mMainToolBar->addAction(mOpenFileAction);

    //Sauvegarde
    mMainToolBar->addAction(mSaveAction);

    //Recherche simple
    mMainToolBar->addAction(mToggleSearchAction);
}

}
