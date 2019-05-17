/*
 * Copyright (c) 2019 M.I.T. License
 *
 * The following source code are data
 * types, macros, and other pieces of 
 * instructions to utilize, in the
 * event an online library is 
 * unavailable or inaccessible.
 *
 * Author(s):
 * + Froz
*/

#ifndef _TYPE_HPP_
#define _TYPE_HPP_
#ifdef __cplusplus
extern "C"
{
#endif

#ifndef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#endif
#ifndef max
#define max(a, b) ((a) > (b) ? (a) : (b))
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef CONST
#define CONST const
#endif

typedef int INT, BOOL;
typedef INT *PINT, *LPINT;
typedef BOOL, *PBOOL, *LPBOOL;
typedef float FLOAT;
typedef FLOAT *PFLOAT, *LPFLOAT;
typedef long *LPLONG;
typedef unsigned char BYTE;
typedef BYTE *PBYTE, *LPBYTE;
typedef unsigned long DWORD;
typedef DWORD *PDWORD, *LPDWORD;
typedef unsigned int UINT;
typedef UINT *PUINT, *LPUINT;
typedef unsigned short WORD;
typedef WORD *PWORD, *LPWORD;
typedef CONST void *PCVOID, *LPCVOID;

#ifdef __cplusplus
}
#endif

#endif // _TYPE_HPP_
