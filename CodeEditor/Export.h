#ifndef EXPORT_H
#define EXPORT_H

#include <QtGlobal>

/*!
    \def CodeEditor_EXPORT
    \details This macro allow symbols to be exported/imported for Window OS
*/

#if defined(CE_LIBRARY)
#define CE_EXPORT Q_DECL_EXPORT
#else
#define CE_EXPORT Q_DECL_IMPORT
#endif

#endif // MONKEY_EXPORT_H
