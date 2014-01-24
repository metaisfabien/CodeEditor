#ifndef EDITOR_EDITOR_WIDGET_H
#define EDITOR_EDITOR_WIDGET_H

#include <QWidget>

namespace CE {
class CentralWidgetTabWidget;
class EditorWidget : public QWidget
{
    Q_OBJECT
public:
    EditorWidget(QWidget *parent=0) { }

    virtual bool isModified() = 0;
    virtual void setText(QString text) = 0;
    virtual void focus();
    virtual void openFile(QString filePath) = 0;
    virtual void save();

    CentralWidgetTabWidget *getParentTabWidget() { return mParentTabWidget; }
    void setParentTabWidget(CentralWidgetTabWidget *parentTabWidget) { mParentTabWidget = parentTabWidget; }

    void setTabText(QString tabText) { mTabText = tabText; }
    QString getTabText() { return mTabText; }

public slots:
    virtual void change();

protected:
    CentralWidgetTabWidget *mParentTabWidget;
    QString mTabText;
};
}
#endif // EDITOR_EDITOR_WIDGET_H
