#ifndef SORT_H
#define SORT_H

#include "errors_structures.h"

#ifdef STATIC
#define SORT_DLL
#define SORT_DECL
#else
#ifdef ARR_EXPORTS
#define SORT_DLL __declspec(dllexport)
#define SORT_DECL __cdecl
#else
#define SORT_DLL __declspec(dllimport)
#define SORT_DECL __cdecl
#endif
#endif

SORT_DLL void SORT_DECL swap(void *p1, void *p2, size_t size);
SORT_DLL void SORT_DECL mysort(void *base, size_t nmemb, size_t size, long long int (*compar)(const void*, const void*));
SORT_DLL long long int SORT_DECL compare_int(const void *p, const void *q);

#endif
