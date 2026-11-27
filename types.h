#ifndef DECLARES_H
#define DECLARES_H

#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

// some snippets from https://nullprogram.com/blog/2023/10/08/ and other places on the web
// and some of my own extensions for making C more "modern"

// PLAN :: re-eval min and max macros, and ptrdiff, uintptr typedefs at some point
// PLAN :: rethink slices, implement arenas real quick

// simple helpful macros
#define countof(a)   (ptrdiff_t)(sizeof(a) / sizeof(*(a)))
#define lengthof(s)  (countof(s) - 1)
#define countbits(x) (sizeof((x)) * 8)
#define mem_zero(x)  (memset((x), 0, sizeof((x))))

// for printf debugging, formatted for emacs compile-mode --------------------
#define error_warn(err_str) do {					\
    fprintf(stderr, "%s:%d: warn: %s", __FILE__, __LINE__, (err_str));	\
  }  while (0)

#define error_exit(err_str) error_warn(err_str); exit(1);

// Iteration Macros
#define Range(lo, hi, iter) (sz (iter)=lo; (iter)<hi; (iter)++)
#define ReverseRange(lo, hi, iter) (sz (iter)=hi; (iter)>lo; (iter)--)

// no stdbool here (in case we arent using c23)
#define true 1
#define false 0

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

typedef struct {
  u64 data;
  u8 cap;
} bset;

void bset_init(bset * bset) {
  bset->data = 0;
  bset->cap = 64;
}

static void bset_clear_all(bset * b)        { b->data = 0; }
static b8   bset_any(bset * b, u64 mask)    { return (b->data & mask) != 0; }
static b8   bset_all(bset * b, u64 mask)    { return (b->data & mask) == 0; }
static void bset_set(bset * b, u64 mask)    { b->data |= mask;  }
static void bset_clear(bset * b, u64 mask)  { b->data &= ~mask; }
static void bset_toggle(bset * b, u64 mask) { b->data ^= mask;  }
static b8   bset_get_index(bset *b, u8 idx) { return (b->data >> idx) & 1u; };

#endif
