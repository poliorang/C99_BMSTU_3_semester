#ifndef KEY_H
#define KEY_H

#include "errors_structures.h"

#ifdef STATIC
#define KEY_DLL
#define KEY_DECL
#else
#ifdef ARR_EXPORTS
#define KEY_DLL __declspec(dllexport)
#define KEY_DECL __cdecl
#else
#define KEY_DLL __declspec(dllimport)
#define KEY_DECL __cdecl
#endif
#endif

KEY_DLL int KEY_DECL count_elems_in_arr(const int *arr, const int *arr_end);
KEY_DLL int KEY_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif
