#ifndef PHPEDITORWIDGET_H
#define PHPEDITORWIDGET_H

#include "Editor/TextEditorWidget.h"

#include <Qsci/qsciscintilla.h>

namespace CE {
class SettingManager;
class PHPEditorWidget : public  TextEditorWidget
{
    Q_OBJECT
public:
    PHPEditorWidget();

public slots:
    void onUpdateSettings();

private:
    SettingManager *mSettingManager;
};
}


#endif // PHPEDITORWIDGET_H
