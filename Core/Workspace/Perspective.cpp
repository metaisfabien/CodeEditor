#include "Workspace/Perspective.h"
#include "Workspace/Dock.h"

using namespace std;
namespace PHPEditor {
Perspective::Perspective(QString name, QString icone)
{
    mName = name;
    mIcone = icone;
}
/**
 * @brief Perspective::~Perspective
 *
 * Detructor
 * Delete the docks in the docks map
 */
Perspective::~Perspective()
{
    map<QString, Dock*>::iterator dockIterator;
    for(dockIterator = mDocks.begin(); dockIterator != mDocks.end(); ++dockIterator) {
        delete dockIterator->second;
    }
}

/**
 * @brief Perspective::addDock
 *
 * Add a dock to the docks map
 *
 * @param Dock* dock dock to addd to the docks map
 */
void Perspective::addDock(Dock *dock)
{
    mDocks.insert(make_pair<QString, Dock*>(dock->getId() , dock));
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
Dock* Perspective::getDock(QString id)
{
    map<QString, Dock*>::iterator dockIterator;
    dockIterator = mDocks.find(id);

    if (dockIterator != mDocks.end()) {
        return dockIterator->second;
    }
    return 0;
}

}
