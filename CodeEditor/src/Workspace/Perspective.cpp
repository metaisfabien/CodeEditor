#include "Workspace/Perspective.h"
#include "Workspace/PerspectiveDock.h"
#include "Dock/Dock.h"

using namespace std;
namespace CE {
Perspective::Perspective(QString name, QString icone)
{
    mName = name;
    mIsCurrent = false;
    mIcone = icone;
    mWindowState = Qt::WindowMaximized;
}

/**
 * @brief Perspective::~Perspective
 *
 * Detructor
 * Delete the dockDatas in the dockDatas QHash
 */
Perspective::~Perspective()
{
    //clear dock hash but not delete because it's deleted by the dock manager
    mPerspectiveDocks.clear();
}

void Perspective::setWindowSize(QString windowSize)
{
    QStringList splitedSize = windowSize.split("x");
    if (splitedSize.at(0) != "" && splitedSize.at(1) != "") {
        mWindowSize = QSize(splitedSize.at(0).toInt(), splitedSize.at(1).toInt());
    }
}

/**
 * @brief Perspective::addDock
 *
 * Add a dock to the docks QHash
 *
 * @param Dock* Dock to addd to the docks QHash
 */
void Perspective::addPerspectiveDock(PerspectiveDock *perspectiveDock)
{
    mPerspectiveDocks[perspectiveDock->getId()] = perspectiveDock;
}

/**
 * @brief Perspective::getDock
 *
 * Search a dock in the docks map by his id and return it
 *
 * @param Qstring id id of the dock to find
 *
 * @return Dock*
 */
PerspectiveDock* Perspective::getPerspectiveDock(QString id)
{
    if (mPerspectiveDocks.contains(id)) {
        return mPerspectiveDocks[id];
    }
    return 0;
}

void Perspective::updateDockArea(QString id, Qt::DockWidgetArea area)
{
    PerspectiveDock *perspectiveDock = getPerspectiveDock(id);
    perspectiveDock->setArea(area);
}
}
