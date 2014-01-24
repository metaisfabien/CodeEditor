#ifndef PHP_BUILDER_H
#define PHP_BUILDER_H

#include <QString>

namespace CE {
class Project;
namespace PHP {
class Builder
{
    public:
        Builder();
        void build(Project *project);

    protected:
        void parseDir(QString dirPath);
        void parseFile(QString filePath);
        QString getFileContent(QString filePath);

};
}
}

#endif //PHP_PLUGIN_H
