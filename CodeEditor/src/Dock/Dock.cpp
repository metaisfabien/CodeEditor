#include "Dock/Dock.h"
#include "Workspace/Perspective.h"

#include "CodeEditor.h"
#include "Workspace/Workspace.h"

namespace CE {

Dock::Dock(QString id, QString title) : QDockWidget(title)
{
    mId = id;
    mIsLoaded = false;

    connect(this, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), this, SLOT(locationChanged(Qt::DockWidgetArea)));
}

void Dock::loadWidget()
{
    if (!mIsLoaded) {
        QWidget *widget = getChildWidget();
        setWidget(widget);
        mIsLoaded = true;
    }
}

void Dock::locationChanged(Qt::DockWidgetArea area)
{
    //check if workspace and current perspective is set because it
    //called first time during the workspace construct
    if (CodeEditor::getWorkspace()) {
        Perspective *currentPerspective = CodeEditor::getWorkspace()->getCurrentPerspective();
        if (currentPerspective)
            currentPerspective->updateDockArea(mId, area);
    }
}

}
