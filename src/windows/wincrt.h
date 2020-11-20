/*
 * Custom implementation for common C runtime functions
 * This makes the DLL essentially freestanding on Windows without having to rely
 * on msvcrt.dll
 */
#ifndef WIN_CRT_H
#define WIN_CRT_H

#include "../util.h"
#include <windows.h>

HANDLE h_heap;

#define STR_LEN(str) (sizeof(str) / sizeof((str)[0]))

void *memset(void *dst, int c, size_t n);
#pragma intrinsic(memset)

void *memcpy(void *dst, const void *src, size_t n);
#pragma intrinsic(memcpy)

size_t strlen_wide(char_t const *str);
#define strlen strlen_wide

void *malloc(size_t size);

void *calloc(size_t num, size_t size);

char_t *strcat_wide(char_t *dst, char_t *src);
#define strcat strcat_wide

char_t *strcpy_wide(char_t *dst, char_t *src);
#define strcpy strcpy_wide

char_t *strncpy_wide(char_t *dst, char_t *src, size_t len);
#define strncpy strncpy_wide

char_t *dirname(char_t *path);

inline void *dlsym(void *handle, const char *name) {
    return GetProcAddress((HMODULE)handle, name);
}

#define RTLD_LAZY 0x00001

inline void *dlopen(const char_t *filename, int flag) {
    return LoadLibrary(filename);
}

inline void free(void *mem) { HeapFree(h_heap, 0, mem); }

inline int setenv(const char_t *name, const char_t *value, int overwrite) {
    return !SetEnvironmentVariable(name, value);
}

char_t *getenv_wide(const char_t *name);
#define getenv getenv_wide

#ifndef UNICODE
#define CommandLineToArgv CommandLineToArgvA
char **CommandLineToArgvA(char *cmd_line, int *argc);
#else
#define CommandLineToArgv CommandLineToArgvW
#endif

#endif