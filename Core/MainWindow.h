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

private:
    void createMenu();
    void createMainToolBar();
    void createActions();

    //actions
    QAction *newFileAction;
    QAction *newProjectAction;
    QAction *openFileAction;
    QAction *saveAction;
    QAction *toggleSearchAction;
    QAction *settingsAction;

    QTabWidget *tabWidget;

    QMenu *fileMenu;
    QToolBar *mainToolBar;

};
}
#endif // MAINWINDOW_H
