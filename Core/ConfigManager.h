#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <map>
#include <QDir>

QT_BEGIN_NAMESPACE
class QString;
class QSettings;
QT_END_NAMESPACE

namespace PHPEditor {
class ConfigManager
{
public:
    ConfigManager();
    bool loadConfig(QString filename);
private:
    QDir configsDir;
    std::map<QString, QSettings*> configs;
};
}

#endif // CONFIGMANAGER_H
