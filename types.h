#ifndef DECLARES_H
#define DECLARES_H

#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

// some snippets from https://nullprogram.com/blog/2023/10/08/ and other places on the web
// and some of my own extensions for making C more "modern"

// PLAN :: re-eval min and max macros, and ptrdiff, uintptr typedefs at some point
// PLAN :: rethink slices, implement arenas real quick

// simple helpful macros
#define countof(a)    (ptrdiff_t)(sizeof(a) / sizeof(*(a)))
#define lengthof(s)   (countof(s) - 1)
#define countbits(x) (sizeof((x)) * 8)

// for printf debugging, formatted for emacs compile-mode --------------------
#define error_warn(err_str) do {					\
    fprintf(stderr, "%s:%d: warn: %s", __FILE__, __LINE__, (err_str));	\
  }  while (0)

#define error_exit(err_str) error_warn(err_str); exit(1);

// Iteration Macros
#define Range(lo, hi) (sz i=lo; i<hi; i++)
#define ReverseRange(lo, hi) (sz i=hi; i>lo; i--)

// useful attributes
#define CACHE_LINE 64
#define UNUSED            __attribute__((unused))
#define FALLTHROUGH       __attribute__((fallthrough));
#define CACHE_ALIGN       __attribute__((aligned(CACHE_LINE)))
#define FORCE_INLINE      __attribute__((always_inline)) static inline
#define PACKED            __attribute__((packed))
#define ALIGN(_size)      __attribute__((aligned(_size)))
#define NO_RETURN         __attribute__((noreturn))

// signed and unsigned types
typedef uint8_t       u8;
typedef uint16_t      u16;
typedef uint32_t      u32;
typedef uint64_t      u64;

typedef int8_t        i8;
typedef int16_t       i16;
typedef int32_t       i32;
typedef int64_t       i64;

typedef float         f32;
typedef double        f64;

typedef unsigned char utf8;

typedef ptrdiff_t size;
typedef void *rawptr;
typedef size_t sz;

// booleans
typedef uint8_t       b8;
typedef uint32_t      b32;

// length based-strings
#define string(s) (string){(u8 *)s, lengthof(s)}
typedef struct {
  u8 * data;
  sz len;
} string;

// small bitmap
typedef struct {
  u8 data[8];
  u16 cap;
} bmap;

void bmap_init(bmap * bmap) {
  memset(bmap->data, 0, sizeof(bmap->data));
  bmap->cap = countbits(bmap->data);			
}

// bitset helpers
static b8 bit_get(const u8 *bmap, u16 i) { return (bmap[i / 8] & (u8)(1u << (i % 8))) != 0; }
static void bit_set(u8 *bmap, u16 i) { bmap[i / 8] |= (u8)(1u << (i % 8)); }
static void bit_clear(u8 *bmap, u16 i) { bmap[i / 8] &= (u8)~(1u << (i % 8)); }


#endif
