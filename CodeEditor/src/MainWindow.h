#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Export.h"

namespace CE {
class MenuBar;
class ActionManager;
class CE_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT
public:
     MainWindow(ActionManager *actionManager, QWidget *parent = 0);
    ~MainWindow();

     QTabWidget* getTab() const { return mTabWidget; }

     MenuBar* menuBar();

signals:
     void closeWindow();
     void stateChange();
     void windowResize(QSize size);

protected:
     void closeEvent(QCloseEvent *event);
     void resizeEvent(QResizeEvent * event);
     void changeEvent(QEvent* e);

private:
    void createMenu();
    void createMainToolBar();
    void createActions();

    ActionManager *mActionManager;

    //actions
    QAction *mNewFileAction;
    QAction *mNewProjectAction;
    QAction *mOpenFileAction;
    QAction *mSaveAction;
    QAction *mToggleSearchAction;
    QAction *mSettingsAction;

    QTabWidget *mTabWidget;
    QToolBar *mMainToolBar;


};
}
#endif // MAINWINDOW_H
