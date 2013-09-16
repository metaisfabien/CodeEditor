#ifndef EXPORT_H
#define EXPORT_H

#include <QtGlobal>

/*!
    \def PHPEDITOR_EXPORT
    \details This macro allow symbols to be exported/imported for Window OS
*/

#if defined(CORE_LIBRARY)
#define PHPEDITOR_EXPORT Q_DECL_EXPORT
#else
#define PHPEDITOR_EXPORT Q_DECL_IMPORT
#endif

#endif // MONKEY_EXPORT_H
