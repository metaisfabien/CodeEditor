#include "Editor/Editor.h"

#include "MainWindow.h"
#include "Core.h"

#include <Qsci/qsciscintilla.h>
#include <QTabWidget>
#include <QFileInfo>
#include <QFile>

#include <QDebug>

namespace PHPEditor {
Editor::Editor()
{

}

void Editor::openFile(QString path)
{
    qDebug() << "Editor::openFile(" + path + ")";
    QString fileName = QFileInfo(path).fileName();

    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString fileContent = file.readAll();

    QsciScintilla *scintilla = new QsciScintilla();
    scintilla->setText(fileContent);
    Core::getMainWindow()->getTab()->addTab(scintilla, fileName);
}

}
