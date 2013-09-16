#include "Core.h"
#include "Application.h"
#include "LogBrowser.h"

#include <qapplication.h>
#include <QPointer>
#include <QDebug>

using namespace PHPEditor;

QPointer<LogBrowser> logBrowser;

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if(logBrowser)
        logBrowser->outputMessage( type, msg );
}

using namespace PHPEditor;

int main(int argc, char *argv[])
{
    Application application(argc, argv);

    logBrowser = new LogBrowser;
    qInstallMessageHandler(myMessageOutput);

    //si un instance est déja lancé on arrete celle ci
    if(application.haveAnotherInstance())return 0;

    Core::init();

    return application.exec();
}
