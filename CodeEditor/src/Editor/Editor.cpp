#include "Editor/Editor.h"
#include "Editor/EditorWidget.h"

#include "MainWindow.h"
#include "CentralWidget/TabWidgetManager.h"
#include "CodeEditor.h"

#include "CentralWidget/TabWidget.h"

#include <QTabWidget>
#include <QFileInfo>
#include <QFile>
#include <QWidget>
#include <QDebug>

#include <Qsci/qsciscintilla.h>
namespace CE {
Editor::Editor(QString id, QString name)
{
    mId = id;
    mName = name;
}

void Editor::openFile(QString path)
{
    qDebug() << "Editor::openFile(" + path + ")";
/*
    QWidgetList *tabWidgets = CodeEditor::getTabWidgetManager()->getTabWidgets();

    for (int i = 0; i < tabWidgets->size(); ++i) {
        CentralWidgetTabWidget *tabWidget = qobject_cast<CentralWidgetTabWidget *>(tabWidgets->at(i));
        for (int y = 0; y < tabWidget->count(); ++y) {
            qDebug() << "open " << i << " " << y << " " << tabWidget->count();

            qDebug() << tabWidget->widget(y);
            EditorWidget *editorWidget = dynamic_cast<EditorWidget *>(tabWidget->widget(y));

             qDebug() << editorWidget;


            if (editorWidget->getFilePath() == path) {
                qDebug() << "file already open";
            }
        }
    }*/

    QString fileContent = getFileContent(path);
    QString fileName = QFileInfo(path).fileName();
    //CodeEditor::getTabWidgetManager()->getFirstTabWidget()->addTab(getEditorWidget(fileContent, path), fileName);
    QsciScintilla *qsci = new QsciScintilla();
    CodeEditor::getTabWidgetManager()->getFirstTabWidget()->addTab(qsci, fileName);

}

QString Editor::getFileContent(QString path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    return file.readAll();
}

}
