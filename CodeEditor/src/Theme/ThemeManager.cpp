#include "Theme/ThemeManager.h"
#include "Theme/Theme.h"

#include <QDir>
#include <QDebug>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QIcon>
#include <QApplication>

namespace CE {
ThemeManager::ThemeManager()
{
    loadThemes();
    mCurrentTheme = getTheme("default");
}

ThemeManager::~ThemeManager()
{
    map<QString, Theme*>::iterator themeIterator;
    for(themeIterator = mThemes.begin(); themeIterator != mThemes.end(); ++themeIterator) {
        delete themeIterator->second;
    }
}

void ThemeManager::loadThemes()
{
    //get the path of the themes dir
    QDir themesDir = QDir(QApplication::applicationDirPath() + "/themes");
    qDebug() << "load themes from: " + themesDir.absolutePath();
    foreach (QString dirName, themesDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        QFile *themeConfigFile = new QFile(themesDir.absolutePath() + "/" + dirName + "/theme.json");
        if (themeConfigFile->exists()) {
            loadTheme(themeConfigFile, themesDir.absolutePath() + "/" + dirName);
        } else {
            qDebug() << "there is no theme.json in the theme folder "  + themesDir.absolutePath() + "/" + dirName;
        }
    }

    if (!themeExist("default")) {
        //throw new Exception("Default theme not exist");
        qDebug() << "Default theme not exist";
    }
}

void ThemeManager::loadTheme(QFile *configFile, QString path)
{
    configFile->open(QIODevice::ReadOnly | QIODevice::Text);
    QString configFileContent = configFile->readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(configFileContent.toUtf8());

    if (jsonDocument.isObject()) {
        QJsonObject themeConfig = jsonDocument.object();
        if (themeConfig["id"].toString() != "") {
            QString id = themeConfig["id"].toString();
            if (!themeExist(id)) {
                QString name = themeConfig["name"].toString();

                Theme *theme = new Theme(id, name, path);
                mThemes.insert(std::make_pair<QString, Theme*>(id, theme));
            } else {
                qDebug() << "theme " + id + " already exist in the theme map";
            }
        } else {
             qDebug() << "theme config file " + configFile->fileName() + " have no id";
        }
    } else {
        qDebug() << "theme config file " + configFile->fileName() + " is not valid";
   }
}


bool ThemeManager::themeExist(QString id)
{
    if (getTheme(id)) {
        return true;
    } else {
        return false;
    }
}

Theme* ThemeManager::getTheme(QString id)
{
    map<QString, Theme*>::iterator themeIterator;
    themeIterator = mThemes.find(id);

    if (themeIterator != mThemes.end()) {
        return themeIterator->second;
    }
    return 0;
}

void ThemeManager::addIcon(QString id, QString fileName)
{
    mIcons.insert(std::make_pair<QString, QString>(id, fileName));
}

QIcon ThemeManager::getThemeIcon(QString fileName)
{
    QFile currentThemeIconeFile(mCurrentTheme->getPath() + "/icons/" + fileName);

    if (!currentThemeIconeFile.exists()) {
        if ( mCurrentTheme->getId() != "default") {
            QFile defaultThemeIconeFile(getTheme("default")->getPath() + "/icons/" + fileName);
            if (defaultThemeIconeFile.exists()) {
                return QIcon(defaultThemeIconeFile.fileName());
            }
        }
        return QIcon(getTheme("default")->getPath() + "/icons/default.png");
    } else {
        return QIcon(currentThemeIconeFile.fileName());
    }
}

QIcon ThemeManager::getIcon(QString id)
{
    map<QString, QString>::iterator iconIterator;
    iconIterator = mIcons.find(id);

    if (iconIterator != mIcons.end()) {
        return getThemeIcon(iconIterator->second);
    }
    return getThemeIcon("default.png");
}

}
