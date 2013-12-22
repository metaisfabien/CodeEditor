TEMPLATE = lib
CONFIG   += plugin

DESTDIR = $$PACKAGE_DESTDIR/plugins/$$PLUGINNAME

install_files.files = plugin.json
install_files.path = $$DESTDIR

## Tell qmake to add the moving of them to the 'install' target
INSTALLS += install_files
