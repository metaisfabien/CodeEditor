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
    configsDir.cd("data");
}

bool ConfigManager::loadConfig(QString filename)
{
    QSettings* settings = new QSettings(configsDir.absoluteFilePath(filename + ".ini"), QSettings::IniFormat);
    configs.insert(std::make_pair<QString, QSettings*>(filename, settings));
    return true;
}
}
