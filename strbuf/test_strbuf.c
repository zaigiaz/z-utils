#include <stdio.h>
#include "strbuf.h"
#include "../csv/csv-parser.h"

int main() {

  const char* big_str = "some/path/here/again";
  const char* small_str = "/new/path";

  strbuf path;
  dsl_rdr myrdr;

  dsl_parse(&myrdr, "s-f-i-i-b-s");
  printf("DSL_STRING: ");
  for(size_t i=0; i<myrdr.len; i++) {
    printf("%d", myrdr.dsl_str[i]);
    if(i == myrdr.len-1) { printf("\n"); }
  }

  strbuf_init(&path);

  // append and pop_right operations ------------------------------
  strbuf_append(&path, "home/");
  printf("%s\n", path.data);

  strbuf_append(&path, big_str);
  printf("\n%s and size %zu", path.data, path.len);

  strbuf_pop_right(&path, sizeof("/again"));
  printf("\n%s", path.data);
  
  strbuf_append(&path, small_str);
  printf("\n%s and %zu", path.data, path.len);

  // pop dir for pathwalking backwards ------------------------------
  strbuf_pop_dir(&path);
  printf("\n%s", path.data);

  // slices that return copy of the buffer into new strbuf ------------------------------
  strbuf s = strbuf_slice(&path, 4, 9);
  printf("\n%*s", s.len, s.data);

  strbuf s_2 = strbuf_slice(&path, 5, 14);
  printf("\n%*s", s_2.len, s_2.data);
}
