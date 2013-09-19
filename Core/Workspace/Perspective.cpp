#include "Workspace/Perspective.h"
#include "Workspace/Dock.h"

using namespace std;
namespace PHPEditor {
Perspective::Perspective(QString _name, QString _icone)
{
    name = _name;
    icone = _icone;
}
/**
 * @brief Perspective::~Perspective
 *
 * Detructor
 * Delete the docks in the docks map
 */
Perspective::~Perspective()
{
    map<string, Dock*>::iterator dockIterator;
    for(dockIterator = docks.begin(); dockIterator != docks.end(); ++dockIterator) {
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
    string id = dock->getId().toStdString();
    docks.insert(make_pair<string, Dock*>(id , dock));
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
    string stdId = id.toStdString();
    map<string, Dock*>::iterator dockIterator;
    dockIterator = docks.find(stdId);

    if (dockIterator != docks.end()) {
        return dockIterator->second;
    }
    return 0;
}

}
