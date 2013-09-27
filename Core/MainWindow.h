#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace PHPEditor {
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();

     QMenu* getNewMenu() const { return mNewMenu; }
     QMenu* getOptionsMenu() const { return mOptionsMenu; }
private:
    void createMenu();
    void createMainToolBar();
    void createActions();

    //actions
    QAction *mNewFileAction;
    QAction *mNewProjectAction;
    QAction *mOpenFileAction;
    QAction *mSaveAction;
    QAction *mToggleSearchAction;
    QAction *mSettingsAction;

    QTabWidget *mTabWidget;

    QMenu *mFileMenu;
    QMenu *mNewMenu;
    QMenu * mOptionsMenu;

    QToolBar *mMainToolBar;

};
}
#endif // MAINWINDOW_H
