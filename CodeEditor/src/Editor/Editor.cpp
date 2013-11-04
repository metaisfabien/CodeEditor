#include "Editor/Editor.h"

#include "MainWindow.h"
#include "CentralWidget/TabWidgetManager.h"
#include "CodeEditor.h"

#include "CentralWidget/TabWidget.h"

#include <Qsci/qsciscintilla.h>
#include <QTabWidget>
#include <QFileInfo>
#include <QFile>

#include <QDebug>

namespace CE {
Editor::Editor(QString id, QString name)
{
    mId = id;
    mName = name;
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
    CodeEditor::getTabWidgetManager()->getFirstTabWidget()->addTab(scintilla, fileName);
}

}
