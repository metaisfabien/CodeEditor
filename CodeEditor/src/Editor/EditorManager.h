#ifndef EDITORMANAGER_H
#define EDITORMANAGER_H

#include "Export.h"

#include <QObject>
#include <QHash>

#include <map>

using namespace std;

namespace CE {
class EditorWidget;
class Editor;
class CE_EXPORT EditorManager : public QObject
{
    Q_OBJECT
public:
    EditorManager();
    ~EditorManager();
    void openFile(QString path);
    void addEditor(Editor *editor);
    Editor* getEditorByExtension(QString extension);
    Editor* getEditorById(QString id);
    map<QString, Editor*> getEditors();

    void setCurrentEditorWidget(EditorWidget *editorWidget);
    EditorWidget *getCurrentEditorWidget() { return mCurrentEditorWidget; }
public slots:
    void saveFile();

private:

    QString getFileContent(QString path);
    QHash<QString, QWidget*> mEditorWidgets;
    map<QString, Editor*> mEditors;
    EditorWidget *mCurrentEditorWidget;
};
}

#endif // PLUGINMANAGER_H
