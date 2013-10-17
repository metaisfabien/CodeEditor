#ifndef PLUGINDATA_H
#define PLUGINDATA_H

#include <QString>
#include <QStringList>

namespace CE {
class PluginData
{
public:
    PluginData(QString id, QString name);

    QString getId() { return mId; }

    void setDescription(QString description) { mDescription = description; }
    void setVersion(QString pluginVersion) { mVersion = pluginVersion; }
    void setCodeEditorMinVerion(QString CodeEditorMinVersion) { mCodeEditorMinVersion = CodeEditorMinVersion; }
    void setPath(QString path) { mPath = path; }
    QString getPath() const { return mPath; }
    void setFileName(QString fileName) { mFileName = fileName; }
    QString getFileName () const { return mFileName; }

    void setIsEnable(bool isEnable) { mIsEnable = isEnable; }
    bool isEnable() const { return mIsEnable; }

    void addDependency(QString dependency);
private:
    QString mId;
    QString mName;
    QString mDescription;
    QString mVersion;
    QString mCodeEditorMinVersion;
    QString mPath;
    QString mFileName;
    QStringList mDependencies;

    bool mIsEnable;
};
}

#endif // PLUGINDATA_H
