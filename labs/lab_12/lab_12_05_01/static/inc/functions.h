#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "errors_structures.h"

#ifdef STATIC
#define FUNC_DLL
#define FUNC_DECL
#else
#ifdef ARR_EXPORTS
#define FUNC_DLL __declspec(dllexport)
#define FUNC_DECL __cdecl
#else
#define FUNC_DLL __declspec(dllimport)
#define FUNC_DECL __cdecl
#endif
#endif

FUNC_DLL int FUNC_DECL create_arr(FILE *f, int **arr, int **arr_end, size_t *n);
FUNC_DLL void FUNC_DECL pack_array(FILE *f, int *arr, const int *arr_end);
FUNC_DLL void FUNC_DECL print_array(FILE *f, const int *arr, const int *arr_end);

#endif
