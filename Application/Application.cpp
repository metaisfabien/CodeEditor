#include "Application.h"

Application::Application(int &argc, char **argv) : QApplication (argc, argv)
//Application::Application(int argc, char *argv[]) : QApplication (argc, argv)
{
    localServerName = "CodeEditorServer";

    QLocalSocket socket;
    socket.connectToServer(localServerName);
    if (socket.waitForConnected(500)) {
        _haveAnotherInstance = true;
    } else {
        _haveAnotherInstance = false;
        localServer = new QLocalServer(this);
        connect(localServer, SIGNAL(newConnection()), this, SLOT(newLocalSocketConnection()));
        localServer->listen(localServerName);
    }
}

Application::~Application()
{

}

bool Application::haveAnotherInstance()
{
    return _haveAnotherInstance;
}
