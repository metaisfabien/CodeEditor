#include "MainWindow.h"
#include "CodeEditor.h"

#include "Plugin/PluginManager.h"
#include "Setting/SettingManager.h"
#include "Theme/ThemeManager.h"
#include "MenuBar.h"

#include <QCoreApplication>
#include <QTabWidget>
#include <QMenu>
#include <QDir>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QTextBrowser>

#include <QDebug>

namespace CE {
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // set menu bar
    setMenuBar(new MenuBar());

    createIcons();
    createActions();
    createMenu();
    createMainToolBar();

    mTabWidget = new QTabWidget();

    setCentralWidget(mTabWidget);
}

MainWindow::~MainWindow()
{
    delete mSettingsAction;
    delete mToggleSearchAction;
    delete mSaveAction;
    delete mOpenFileAction,
    delete mNewFileAction;
    delete mTabWidget;
}

void MainWindow::createIcons()
{
   ThemeManager* themeManager = CodeEditor::getThemeManager();
   themeManager->addIcon("new", "new.png");
   themeManager->addIcon("open", "open.png");
   themeManager->addIcon("save", "save.png");
   themeManager->addIcon("search", "search.png");
   themeManager->addIcon("setting", "setting.png");
   themeManager->addIcon("plugin", "plugin.png");
   themeManager->addIcon("add", "add.png");
   themeManager->addIcon("remove", "remove.png");
   themeManager->addIcon("edit", "edit.png");

}

/**
 * Crée les actions du programme
 *
 * @brief MainWindow::createActions
 */
void MainWindow::createActions()
{
    //Nouveau
    mNewFileAction = new QAction(CodeEditor::getThemeManager()->getIcon("new"), tr("&File"), this);
    mNewFileAction->setShortcuts(QKeySequence::New);
    mNewFileAction->setStatusTip(tr("file"));

    //Ouvrir fichier
    mOpenFileAction = new QAction(CodeEditor::getThemeManager()->getIcon("open"), tr("&Open file"), this);
    mOpenFileAction->setShortcuts(QKeySequence::Open);
    mOpenFileAction->setStatusTip(tr("open file"));

    //Sauvegarder
    mSaveAction = new QAction(CodeEditor::getThemeManager()->getIcon("save"), tr("&Save"), this);
    mSaveAction->setShortcuts(QKeySequence::Save);
    mSaveAction->setStatusTip(tr("save"));

    //Rechercher
    mToggleSearchAction = new QAction(CodeEditor::getThemeManager()->getIcon("search"), tr("&Search"), this);
    mToggleSearchAction->setShortcuts(QKeySequence::Find);
    mToggleSearchAction->setStatusTip(tr("search"));

    mSettingsAction = new QAction(CodeEditor::getThemeManager()->getIcon("setting"), tr("&Settings"), this);
    mSettingsAction->setStatusTip(tr("settings"));
    QObject::connect(mSettingsAction, SIGNAL(triggered()), CodeEditor::getSettingManager(), SLOT(showSettingsDialog()));
}

/**
 * @brief MainWindow::createMenu
 *
 * Create the default main menu
 */
void MainWindow::createMenu()
{
    //CodeEditor::getMenuManager()->menu
    menuBar()->menu("file", tr("&File"));
    QMenu *newFileMenu = menuBar()->menu("file/new", tr("&New"));

    newFileMenu->addAction(mNewFileAction);

    newFileMenu->addAction(mOpenFileAction);
    newFileMenu->addAction(mSaveAction);

    QMenu *toolsMenu = menuBar()->menu("tools", tr("&Tools"));
    toolsMenu->addAction(mSettingsAction);
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

MenuBar* MainWindow::menuBar()
{
    return qobject_cast<MenuBar*>( QMainWindow::menuBar() );
}
}
