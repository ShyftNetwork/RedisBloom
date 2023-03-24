
#pragma once

#if (defined(DEBUG) || defined(_DEBUG)) && !defined(NDEBUG)

#include <stdbool.h>

extern bool __via_gdb;

#if defined(__arm__)
#define BB do { if (__via_gdb) { __asm__("trap"); } } while(0)
#elif defined(__aarch64__)
#define BB do { if (__via_gdb) { __builtin_debugtrap(); } } while(0)
#else
#define BB do { if (__via_gdb) { __asm__("int $3"); } } while(0)
#endif

#elif defined(READIES_ALLOW_BB)

#define BB do {} while(0)

#endif // DEBUG
