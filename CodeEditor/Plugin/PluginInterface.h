#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QString>
#include <QPluginLoader>

namespace CE {
class PluginInterface
{
public:
   //virtual PluginInterface();
    virtual ~PluginInterface() {}

    virtual bool load() = 0;
    virtual bool unLoad() = 0;

    QString getId(){ return id; }
    bool getIsLoaded(){ return isLoaded; }
    QString getVersion(){ return version; }

protected:
    QString id;
    QString version;
    bool isLoaded;

};

}
QT_BEGIN_NAMESPACE
#define PluginInterface_iid "org.CodeEditor.Default.PluginInterface"
Q_DECLARE_INTERFACE(CE::PluginInterface, PluginInterface_iid)
/*Q_DECLARE_INTERFACE(PluginInterface, "org.CodeEditor.Default.PluginInterface/1.0")*/
QT_END_NAMESPACE

#endif // PLUGININTERFACE_H
