#ifndef EDITORMANAGER_H
#define EDITORMANAGER_H

#include "Export.h"

#include <QObject>

#include <map>

using namespace std;

namespace PHPEditor {
class Editor;
class PHPEDITOR_EXPORT EditorManager : public QObject
{
    Q_OBJECT
public:
    EditorManager();
    ~EditorManager();
    void openFile(QString path);
    void addEditor(QString id, Editor *editor);
    Editor* getEditorByExtension(QString extension);
    Editor* getEditorById(QString id);

public slots:


private:

    map<QString, Editor*> mEditor;
};
}

#endif // PLUGINMANAGER_H
