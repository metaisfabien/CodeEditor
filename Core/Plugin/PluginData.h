#ifndef PLUGINDATA_H
#define PLUGINDATA_H

#include <QString>

namespace PHPEditor {
class PluginData
{
public:
    PluginData(QString id, QString name);

    void setDescription(QString description) { mDescription = description; }
private:
    QString mId;
    QString mName;
    QString mDescription;
};
}

#endif // PLUGINDATA_H
