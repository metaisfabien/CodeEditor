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

    tabWidget = new QTabWidget();
/*
    QsciScintilla *scintilla = new QsciScintilla(this);
    tabWidget->addTab(scintilla,"TAB 1");
*/
    setCentralWidget(tabWidget);
}

MainWindow::~MainWindow()
{
    delete settingsAction;
    delete toggleSearchAction;
    delete saveAction;
    delete openFileAction,
    delete newFileAction;
    delete tabWidget;
}

/**
 * Crée les actions du programme
 *
 * @brief MainWindow::createActions
 */
void MainWindow::createActions()
{
    //Nouveau
    newFileAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/new.png"), tr("&File"), this);
    newFileAction->setShortcuts(QKeySequence::New);
    newFileAction->setStatusTip(tr("File"));

    //Ouvrir fichier
    openFileAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/open.png"), tr("&Open file"), this);
    openFileAction->setShortcuts(QKeySequence::Open);
    openFileAction->setStatusTip(tr("Open file"));

    //Sauvegarder
    saveAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/save.png"), tr("&Sauvegarder"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Sauvegarder"));

    //Rechercher
    toggleSearchAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/search.png"), tr("&Chercher"), this);
    toggleSearchAction->setShortcuts(QKeySequence::Find);
    toggleSearchAction->setStatusTip(tr("Chercher"));

    settingsAction = new QAction(QIcon(QCoreApplication::applicationDirPath() +"/images/setting.png"), tr("&Configuration"), this);
    settingsAction->setStatusTip(tr("configuration"));

}

void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu(tr("&File"));

    newMenu = fileMenu->addMenu(tr("&New"));
    newMenu->addAction(newFileAction);


    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveAction);
}

/**
 * Crée le toolbar principal
 * @brief MainWindow::createMainToolBar
 */
void MainWindow::createMainToolBar()
{
    //creation de la toolbar
    mainToolBar = new QToolBar;
    addToolBar(Qt::TopToolBarArea, mainToolBar);

    //Nouveau fichier
    mainToolBar->addAction(newFileAction);

    //Ouvrir fichier
    mainToolBar->addAction(openFileAction);

    //Sauvegarde
    mainToolBar->addAction(saveAction);

    //Recherche simple
    mainToolBar->addAction(toggleSearchAction);

    //Configuration
    mainToolBar->addAction(settingsAction);
}

}
