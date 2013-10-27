#include "CodeEditor.h"
#include "Application.h"
#include "LogBrowser.h"

#include <qapplication.h>
#include <QPointer>
#include <QDebug>
#include <QFile>
#include <QDir>

using namespace CE;

QPointer<LogBrowser> logBrowser;

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if(logBrowser)
        logBrowser->outputMessage( type, msg );


    QDir logDir = QDir(QApplication::applicationDirPath());


    QFile file(logDir.absoluteFilePath("debug.log"));
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream out(&file);
    out << msg << "\n";

    // optional, as QFile destructor will already do it:
    file.close();
}


int main(int argc, char** argv)
//int main(int argc, char *argv[])
{
    Application application(argc, argv);

    logBrowser = new LogBrowser;
    qInstallMessageHandler(myMessageOutput);

    //si un instance est déja lancé on arrete celle ci
    if(application.haveAnotherInstance())return 0;

    CodeEditor::init();

    return application.exec();
}
