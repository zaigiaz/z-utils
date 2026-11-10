#include <stdbool.h>
#include <string.h>
#include "../types.h"

#define MAP_CAPACITY 1024
#define MAX_KEY_LEN  32-1 // null terminator
#define BUCKET_COUNT 256+1 // 256 different chars (could restrict to 26)
#define NONE         0xFFFFu

typedef struct {
    char keys[MAP_CAPACITY][MAX_KEY_LEN + 1];
    u32 values[MAP_CAPACITY];
    u16 next[MAP_CAPACITY];

    // Head index for each bucket; NONE means empty.
    u16 head[BUCKET_COUNT];
    u16 count;
} str_map;

static u32 bucket_of(const char *key) {
    if (key[0] == '\0')
        return 0;
    return 1u + (unsigned char)key[0];
}

static void map_init(str_map *map) {
    map->count = 0;
    for (u32 b = 0; b < BUCKET_COUNT; ++b)
        map->head[b] = NONE;
}

static bool map_insert(str_map *map, const char *key, u32 value) {
    size_t len = strlen(key);
    if (len > MAX_KEY_LEN) {      
        return false;
    }

    u32 bucket = bucket_of(key);

    // Replace the value if the key already exists.
    for (u16 i = map->head[bucket]; i != NONE; i = map->next[i]) {
        if (strcmp(map->keys[i], key) == 0) {
            map->values[i] = value;
            return true;
        }
    }

    if(map->count == MAP_CAPACITY) {
        fprintf(stderr, "At total map capacity for the str_map");
        return false;
    }

    u16 i = map->count++;
    memcpy(map->keys[i], key, len + 1);
    map->values[i] = value;

    // Link the new entry at the front of its bucket.
    map->next[i] = map->head[bucket];
    map->head[bucket] = i;

    return true;
}

static const u32 *map_find(const str_map *map, const char *key) {
    u32 bucket = bucket_of(key);

    for (u16 i = map->head[bucket]; i != NONE; i = map->next[i]) {
        if (strcmp(map->keys[i], key) == 0)
            return &map->values[i];
    }

    return NULL;
}
