#ifndef LOGBROWSERDIALOG_H
#define LOGBROWSERDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QTextBrowser;
class QPushButton;
QT_END_NAMESPACE

namespace PHPEditor {
class LogBrowserDialog : public QDialog
{
    Q_OBJECT

public:
    LogBrowserDialog(QWidget *parent = 0);
    ~LogBrowserDialog();

public slots:
    void outputMessage( QtMsgType type, const QString &msg );

protected slots:
    void save();

protected:
    virtual void keyPressEvent( QKeyEvent *e );
    virtual void closeEvent( QCloseEvent *e );

    QTextBrowser *browser;
    QPushButton *clearButton;
    QPushButton *saveButton;
};
}

#endif // LOGBROWSERDIALOG_H
