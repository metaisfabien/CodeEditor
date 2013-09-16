#include "ConfigManager.h"

#include <QApplication>
#include <QDir>
#include <QString>
#include <QSettings>

namespace PHPEditor {
ConfigManager::ConfigManager()
{
    //On récupère le path du dossier des plugins
    configsDir = QDir(QApplication::applicationDirPath());

    #if defined(Q_OS_WIN)
        if (configsDir.dirName().toLower() == "debug" || configsDir.dirName().toLower() == "release")
            configsDir.cdUp();
    #elif defined(Q_OS_MAC)
        if (configsDir.dirName() == "MacOS") {
            configsDir.cdUp();
            configsDir.cdUp();
            configsDir.cdUp();
        }
    #endif
    configsDir.cd("config");
}

bool ConfigManager::loadConfig(QString filename)
{
    QSettings* settings = new QSettings(configsDir.absoluteFilePath(filename + ".ini"), QSettings::IniFormat);
    configs.insert(std::make_pair<QString, QSettings*>(filename, settings));
    return true;
}
}
