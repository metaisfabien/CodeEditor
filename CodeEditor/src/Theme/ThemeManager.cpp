#include "Theme/ThemeManager.h"
#include "Theme/Theme.h"
#include "MainWindow.h"
#include "CodeEditor.h"

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
                mThemes.insert(std::make_pair(id, theme));
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


QIcon ThemeManager::getIcon(QString fileName)
{
    return QIcon(QApplication::applicationDirPath() + "/icons/" + fileName);
}

QIcon ThemeManager::getExtensionIcon(QString fileName)
{
    QString iconPath = QApplication::applicationDirPath() + "/icons/extensions/" + fileName;
    if (QFile(iconPath).exists()) {
        return QIcon(iconPath);
    } else {
        return QIcon(QApplication::applicationDirPath() + "/icons/extensions/default.png");
    }

}

void ThemeManager::setCurrentTheme(QString themeId)
{
    mCurrentTheme = getTheme(themeId);

    QFile styleSheetFile(mCurrentTheme->getPath() + "/stylesheet.qss");
    if (styleSheetFile.exists()) {
        qDebug() << "Load stylesheet " << styleSheetFile.fileName();
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        //QApplication::instance()->
        CodeEditor::getMainWindow()->setStyleSheet(styleSheet);
    } else {
        CodeEditor::getMainWindow()->setStyleSheet("");
    }
}
}
