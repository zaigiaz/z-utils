#ifndef STRLIB
#define STRLIB

#include <string.h>
#include "../types.h"

// re-implement with arenas
string str_append_cstring(string first, char * txt);

// TODO :: create these functions
string str_append(string first, string txt, Arena *arena);
string str_has_prefix(string str, string prefix);
string str_has_suffix(string str, string suffix);
string str_to_integer(string first);
string integer_to_string(string first, u64 number);
b32 str_eq(string first, string second);

// TODO :: re-think these
string str_trim_right_dirty(string first, sz amt);
string str_trim_right(string first, sz trm);
string str_trim_left(string first, sz trm);

// TODO :: FINISH
string str_append(string first, string second, Arena * arena) {
  new_length = first.len + second.len;
}

// TODO :: add reallocate logic plz with arena
string str_append_cstring(string first, char * txt) {
  sz iter = strlen(txt);

  /* for(iter; iter<first.len; iter++) { */
  for Range(iter, first.len) {
    first.data[iter];
  }
  
  return first;
}

// chop off from end of string, but data still exists
string str_trim_right_dirty(string first, sz amt) {
  if (first.len < amt) error_exit("cant trim more than the entire string length");
  first.len = first.len - amt;    
  return first;
}

// allocate a new string instead of just changing the lenght in the type
string str_trim_right(string first, sz trm) {

  string newstr;

  sz j=0;
  sz new_end = first.len - trm;
  newstr.len = new_end;
  
  /* for(sz i=first.len; i>new_end; i--) { */
  for ReverseRange(first.len, new_end) {
    newstr.data[j] = first.data[i];
    j++;
  }

  return newstr;
}

// allocate new copy unless we include two pointers in str8 impl
// this is slightly more expensive but should happen rarely
// TODO :: rewrite this without for-loop, either memcpy or 
string str_trim_left(string first, sz trm) {

  string newstr;
  sz j=0;

  newstr.len = first.len - trm;  
  for Range(trm, first.len) {
    newstr.data[j] = first.data[i];
    j++;
  }

  return newstr;
}

#endif

