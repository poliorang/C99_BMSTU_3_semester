#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <stdlib.h>

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

ARR_DLL void ARR_DECL fill_fibonacci(int *array, int count);
ARR_DLL int ARR_DECL filter(int *src, int src_len, int *dst, int *dst_len);

#endif
