#ifndef STRLIB
#define STRLIB

// NOTE ::
// Older experiment from when I tried to take basic lenght-based strings
// and make them into a general string type. This is possible but was kind of awkward.
// I ended up just defaulting to my later strbuf design later.

str8 str_append(s8 first, char * txt);
str8 str_trim_right_dirty(s8 first, char * txt);
str8 str_trim_right(s8 first, usize trm);
str8 str_trim_left(s8 first, usize trm);
str8 slice(s8 string, usize left, usize right);

// add reallocate logic plz
str8 str_append(s8 first, char * txt) {
  usize iter = strlen(first.data);

  for(iter; iter<first.len; iter++) {
    first.data[iter];
  }
  
  return first;
}

// chop off from end of string, but data still exists
str8 str_trim_right_dirty(str8 first, char * txt) {
  usize iter = strlen(txt);
  first.len = first.len - iter;  
  
  return first;
}

// allocate a new string instead of just changing the lenght in the type
str8 str_trim_right(str8 first, usize trm) {

  str8 newstr;

  usize j=0;
  usize new_end = first.len - trm;
  newstr.len = new_end;
  
  for(usize i=first.len; i>new_end; i--) {
    newstr.data[j] = first.data[i];
    j++;
  }

  return newstr;
}

// allocate new copy unless we include two pointers in str8 impl
// this is slightly more expensive but should happen rarely
// TODO :: rewrite this without for-loop, either memcpy or 
str8 str_trim_left(str8 first, usize trm) {

  str8 newstr;
  usize j=0;

  newstr.len = first.len - trm;  
  for(usize i=trm; i<first.len; i++) {
    newstr.data[j] = first.data[i];
    j++;
  }

  return newstr;
}

// TODO :: same as strbuf logic
str8 slice(str8 string, usize left, usize right) {
  printf("implement here");
}

#endif

