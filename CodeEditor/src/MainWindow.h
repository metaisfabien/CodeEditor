#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Export.h"

namespace CE {
class MenuBar;
class CE_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT
public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();

     QTabWidget* getTab() const { return mTabWidget; }

     MenuBar* menuBar();
private:
    void createIcons();
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
    QToolBar *mMainToolBar;


};
}
#endif // MAINWINDOW_H
