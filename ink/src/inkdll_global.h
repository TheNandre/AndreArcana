#ifndef INKDLL_GLOBAL_H
#define INKDLL_GLOBAL_H

#include <QtGlobal>

#if defined(INK_LIBRARY)
#  define INK_EXPORT Q_DECL_EXPORT
#else
#  define INK_EXPORT Q_DECL_IMPORT
#endif

#endif // INKDLL_GLOBAL_H
