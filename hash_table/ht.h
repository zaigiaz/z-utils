#ifndef HT_H
#define HT_H

// type generic hash table

#include "../types.h"

#define ht_init(ht, size)
#define ht_insert(ht, key, value)
#define ht_get(ht, key)

#define FNV_OFFSET_BASIS 14695981039346656037ull
#define FNV_PRIME 1099511628211ull

// taken from dear friend cadr (not sorry)
u64 fnv1a_hash(u8 *buf, size_t size) {
  u64 hash = FNV_OFFSET_BASIS;
  for Length(size) {
    hash = hash ^ (u64)buf[i];
    hash = hash * FNV_PRIME;
  }
  return hash;
}



#endif
