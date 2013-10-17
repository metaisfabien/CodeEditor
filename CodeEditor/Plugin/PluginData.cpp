#include "Plugin/PluginData.h"

namespace CE {
PluginData::PluginData(QString id, QString name)
{
    mId = id;
    mName = name;
}

void PluginData::addDependency(QString dependency)
{
    mDependencies << dependency;
}
}
