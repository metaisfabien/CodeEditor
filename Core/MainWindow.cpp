#include "MainWindow.h"
#include "Core.h"

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

  //  mTabWidget = new QTabWidget();
/*
    QsciScintilla *scintilla = new QsciScintilla(this);
    tabWidget->addTab(scintilla,"TAB 1");
*/
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
    mNewFileAction->setStatusTip(tr("File"));

    //Ouvrir fichier
    mOpenFileAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/open.png"), tr("&Open file"), this);
    mOpenFileAction->setShortcuts(QKeySequence::Open);
    mOpenFileAction->setStatusTip(tr("Open file"));

    //Sauvegarder
    mSaveAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/save.png"), tr("&Sauvegarder"), this);
    mSaveAction->setShortcuts(QKeySequence::Save);
    mSaveAction->setStatusTip(tr("Sauvegarder"));

    //Rechercher
    mToggleSearchAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/search.png"), tr("&Chercher"), this);
    mToggleSearchAction->setShortcuts(QKeySequence::Find);
    mToggleSearchAction->setStatusTip(tr("Chercher"));

    mSettingsAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/setting.png"), tr("&Configuration"), this);
    mSettingsAction->setStatusTip(tr("configuration"));

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

    mOptionsMenu = menuBar()->addMenu(tr("&Options"));
    mOptionsMenu->addAction(mSettingsAction);
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
