#include <stdio.h>
#include "types.h"

int main(void) {
  u32 values[] = {1, 2, 51, 25, 6};
  array newvals = array(values);
  
  for(size_t i=0; i<newvals.len; i++) {
    printf("\n%u", array_at(newvals, u32, i));
  }
}

