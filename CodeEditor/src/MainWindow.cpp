#include "MainWindow.h"
#include "CodeEditor.h"

#include "Plugin/PluginManager.h"
#include "Setting/SettingManager.h"
#include "Theme/ThemeManager.h"
#include "Workspace/Workspace.h"
#include "Workspace/Perspective.h"
#include "Menu/MenuBar.h"
#include "Action/Manager.h"


#include "CentralWidget/TabWidgetManager.h"
#include "CentralWidget/CentralWidget.h"

#include <QCoreApplication>
#include <QMenu>
#include <QDir>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QTextBrowser>
#include <QWindowStateChangeEvent>

#include <QDebug>


namespace CE {
MainWindow::MainWindow(ActionManager *actionManager, TabWidgetManager *tabWidgetManager, QWidget *parent) : QMainWindow(parent)
{
    qDebug() << "MainWindow::MainWindow";

    mActionManager = actionManager;

    // set menu bar
    setMenuBar(new MenuBar());

    createActions();
    createMenu();
    createMainToolBar();

    CentralWidget *centralWidget_ = new CentralWidget(tabWidgetManager, this);
    setCentralWidget(centralWidget_);
}

MainWindow::~MainWindow()
{
    delete mSettingsAction;
    delete mToggleSearchAction;
    delete mSaveAction;
    delete mOpenFileAction,
    delete mNewFileAction;
}


/**
 * Crée les actions du programme
 *
 * @brief MainWindow::createActions
 */
void MainWindow::createActions()
{
    //Nouveau

    mNewFileAction = mActionManager->createAction("new_file", tr("&File"), this, CodeEditor::getThemeManager()->getIcon("new.png"));
    mNewFileAction->setShortcuts(QKeySequence::New);
    mNewFileAction->setStatusTip(tr("file"));

    //Ouvrir fichier
    mOpenFileAction = new QAction(CodeEditor::getThemeManager()->getIcon("open.png"), tr("&Open file"), this);
    mOpenFileAction->setShortcuts(QKeySequence::Open);
    mOpenFileAction->setStatusTip(tr("open file"));

    //Sauvegarder
    mSaveAction = new QAction(CodeEditor::getThemeManager()->getIcon("save.png"), tr("&Save"), this);
    mSaveAction->setShortcuts(QKeySequence::Save);
    mSaveAction->setStatusTip(tr("save"));

    //Rechercher
    mToggleSearchAction = new QAction(CodeEditor::getThemeManager()->getIcon("search.png"), tr("&Search"), this);
    mToggleSearchAction->setShortcuts(QKeySequence::Find);
    mToggleSearchAction->setStatusTip(tr("search"));

    mSettingsAction = new QAction(CodeEditor::getThemeManager()->getIcon("setting.png"), tr("&Settings"), this);
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

    newFileMenu->addAction(mActionManager->getAction("new_file"));

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

void MainWindow::closeEvent(QCloseEvent *event)
{
    emit closeWindow();
    QMainWindow::closeEvent(event);
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    emit windowResize(size());
    QMainWindow::resizeEvent(event);
}

void MainWindow::changeEvent(QEvent* e)
{
    if(e->type() == QEvent::WindowStateChange) {
        emit stateChange();
    }
    QMainWindow::changeEvent(e);
}
}
