#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QString>
#include <map>

QT_BEGIN_NAMESPACE
class QFile;
class QIcon;
QT_END_NAMESPACE

using namespace std;

namespace CE {
class Theme;
class ThemeManager
{
public:
    ThemeManager();
    ~ThemeManager();
    void loadThemes();
    void loadTheme(QFile *configFile, QString path);
    bool themeExist(QString id);
    Theme* getTheme(QString id);
    map<QString, Theme*> getThemes() const { return mThemes; }

    void addIcon(QString id, QString fileName);
    QIcon getIcon(QString id);

private:
    QIcon getThemeIcon(QString fileName);

    Theme *mCurrentTheme;
    map<QString, Theme*> mThemes;
    map<QString, QString> mIcons;
};
}

#endif // THEMEMANAGER_H
