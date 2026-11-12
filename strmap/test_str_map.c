#include <stdio.h>
#include "str-map.h"

int main(void) {

  str_map map;
  map_init(&map);

  map_insert(&map, "mystr", 25);
  map_insert(&map, "mything", 65);
  map_insert(&map, "mysng", 10);
  map_insert(&map, "ad", 115);
  map_insert(&map, "tiuo", 26);
  map_insert(&map, "main_header", 87);

  const u32 *val = map_find(&map, "mystr");
  printf("value_from_map: %d\n", *val);

  const u32 *next_val = map_find(&map, "tiuo");
  printf("value_from_map: %d\n", *next_val);


  printf("working");
}
