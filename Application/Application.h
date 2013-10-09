#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QLocalServer>
#include <QLocalSocket>

class Application : public QApplication
{
    Q_OBJECT
    public:
        Application(int &argc, char **argv);
        //Application(int argc, char *argv[]);

        ~Application();

        bool haveAnotherInstance();
    private:
        QLocalServer *localServer;
        char *localServerName;
        bool _haveAnotherInstance;
};

#endif // APPLICATION_H
