#ifndef STRLIB
#define STRLIB

#include <string.h>
#include "../types.h"

// TODO :: re-implement with arenas
string str_append_cstring(string s, char * txt, Arena *arena);

// TODO :: create these functions
string str_append(string s, string txt, Arena *arena);
string str_has_prefix(string str, string prefix);
string str_has_suffix(string str, string suffix);
b32 str_eq(string a, string b);

// TODO :: conversion functions to numbers
i32 str_to_integer(string s);
string int_to_str(i32 num);
f32 str_to_float(string s);
string float_to_str(f32 num);

// TODO :: re-think these (slice and trim types)
string str_trim_right(string s, sz trm);
string str_trim_left(string s, sz trm);
string string_copy_slice(string s);

// TODO :: FINISH
string str_append(string first, string second, Arena * arena) {
  new_length = first.len + second.len;
}

// TODO :: add reallocate logic plz with arena
string str_append_cstring(string s, char * txt) {
  sz iter = strlen(txt);

  /* for(iter; iter<first.len; iter++) { */
  for Range(iter, first.len) {
    first.data[iter];
  }
  
  return first;
}

string string_copy_slice(string a) {
  return 0;
}

// chop off from end of string, but data still exists
string str_trim_right_dirty(string s, sz amt) {
  if (first.len < amt) error_exit("cant trim more than the entire string length");
  first.len = first.len - amt;    
  return first;
}


#endif

