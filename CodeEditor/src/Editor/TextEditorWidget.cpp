#include "Editor/TextEditorWidget.h"

#include <Qsci/qsciscintilla.h>

#include <QHBoxLayout>
#include <QEvent>
#include <QFile>
#include <QTextStream>

namespace CE {

TextEditorWidget::TextEditorWidget()
{
    mCurrentFilePath = "";

    QHBoxLayout *layout = new QHBoxLayout(this);

    mQsciScintilla = new QsciScintilla(this);

    connect(mQsciScintilla, SIGNAL(textChanged()), this, SLOT(change()));

    //add event filter on the QsciScintilla widget
    mQsciScintilla->installEventFilter(this);
    layout->addWidget(mQsciScintilla);
}


bool TextEditorWidget::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn) {
        focus();
    } else if (event->type() == QEvent::FocusOut) {
    }

    return QObject::eventFilter(object, event);
}

void TextEditorWidget::focus()
{
    mQsciScintilla->setFocus(Qt::MouseFocusReason);
    EditorWidget::focus();
}

bool TextEditorWidget::isModified()
{
    return mQsciScintilla->isModified();
}

void TextEditorWidget::setText(QString text)
{
    mQsciScintilla->setText(text);
    mQsciScintilla->setModified(false);
    change();
}

void TextEditorWidget::openFile(QString filePath)
{
    QString fileContent = getFileContent(filePath);
    setText(fileContent);
    mCurrentFilePath = filePath;
}

void TextEditorWidget::save()
{
    QFile file(mCurrentFilePath);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream textStream(&file);
    textStream << mQsciScintilla->text();

    file.close();
    mQsciScintilla->setModified(false);
    EditorWidget::save();
}

QString TextEditorWidget::getFileContent(QString filePath)
{
    QFile file(filePath);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    return file.readAll();
}

}
