#ifndef BIGOPT_H
#define BIGOPT_H

#include "../types.h"

// linked lists of potential values that we walk
// can add expected value into parser.
// name that is included in strmap that we can then just grab with api? (too heavy)
// or rather I would just like to have linked-list -> struct?
// I want to accept both '-' and '--'

typedef enum : u8 {
    VAL_I32,
    VAL_F32,
    VAL_STRING,
    VAL_BOOL
} val_type;

union data_t {
  i32 number_t;
  f32 float_t;
  s8  str_t;
  b8  bool_t;
};

typedef struct val_node val_node;
struct val_node {
  s8 name;
  b8 optional;
  val_type value_type;
  union data_t data;
  val_node *next;
};

void add_argument(const char* name, char type, s8 desc) {
  return;
}

void argval_error() {
  fprintf(stderr, "you fucked up bud");
  return;
}

#endif
