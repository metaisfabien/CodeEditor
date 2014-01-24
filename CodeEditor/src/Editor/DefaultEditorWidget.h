#ifndef EDITOR_DEFAULT_EDITOR_WIDGET_H
#define EDITOR_DEFAULT_EDITOR_WIDGET_H

#include "Editor/TextEditorWidget.h"


namespace CE {
class SettingManager;
class DefaultEditorWidget : public TextEditorWidget
{
    Q_OBJECT
public:
    DefaultEditorWidget();
public slots:
    void onUpdateSettings();

private:
    SettingManager *mSettingManager;
};
}

#endif // EDITOR_DEFAULT_EDITOR_WIDGET_H
