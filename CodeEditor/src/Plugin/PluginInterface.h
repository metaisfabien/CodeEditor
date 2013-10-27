#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H


#include <QString>
#include <QPluginLoader>
#include <QHash>

namespace CE {
class Dock;
class PluginInterface
{
public:
    //virtual PluginInterface() = 0;
    //virtual ~PluginInterface() = 0;

    virtual bool load() = 0;
    virtual bool unLoad() = 0;
    virtual QHash <QString, Dock*> getDocks() = 0;

    QString getId() const { return mId; }
    bool getIsLoaded() const { return mIsLoaded; }

protected:
    QString mId;
    bool mIsLoaded;
};

}
QT_BEGIN_NAMESPACE
#define PluginInterface_iid "org.CodeEditor.Default.PluginInterface"
Q_DECLARE_INTERFACE(CE::PluginInterface, PluginInterface_iid)
/*Q_DECLARE_INTERFACE(PluginInterface, "org.CodeEditor.Default.PluginInterface/1.0")*/
QT_END_NAMESPACE

#endif // PLUGININTERFACE_H
