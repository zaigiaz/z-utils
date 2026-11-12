#ifndef CSV_PARSER
#define CSV_PARSER

#include "../strbuf/strbuf.h"

// csv_reader assumes that there is no csv_header according the RFC rules
// if there is then just be aware that we will return a line of strings or potentially malformed data otherwise for now

// implement basic dsl_reader so that we can have the schema enforced on api call like in jannson with "s-f-b-i"
// that expands out into schema [string, float, bool, integer, newline] 

// delimiter is anything of our choosing, so we could read .dat files as well

// TODO :: if schema breaks then return null or?
// TODO :: whats the return structure of the api? a linked list?
//         or just expect hand-rolled solution per-project?

// TODO :: Reset, Clear, and other functions for the reader

// 8 KB init-size
#define CSV_SIZE 8*1024

typedef enum : u8 {
  STRING,
  FLOAT,
  INTEGER,
  BOOL,
  DELIM,
  NEWLINE,
  NOTOK
} csv_type;

// slices into strbuf
typedef struct {
  u16 base[CSV_SIZE];
  u16 offset[CSV_SIZE];
  csv_type type_tok[CSV_SIZE];
  char delim;
} csv_rdr;

// for defining the csv schema. Max of 32 fields
typedef struct {
  char dsl_str[32+1]; 
  u8 len;
} dsl_rdr;

union data_t {
  i32 number_t;
  f32 float_t;
  char * str_t;
  bool bool_t;
};

typedef struct result_list result_list;
struct result_list {
  csv_type tok_type;
  union data_t data;
  result_list * next;
}; 

void csv_rdr_init(csv_rdr * rdr, char delim);
bool is_delim(csv_rdr* r, char c);
void dsl_parse(dsl_rdr * d, const char* c);

void csv_rdr_init(csv_rdr* rdr, char my_delim) {
  rdr->delim = my_delim;  
}

bool is_delim(csv_rdr *r, char c) {
    return c == r->delim || c == '\n' || c == '\r';
}

void dsl_parse(dsl_rdr * d, const char* str) {

  memset(&d->dsl_str, NOTOK, 32+1);
  d->len = 0;

  // 32 inputs + 31 delimiters = 63 total chars
  size_t input_len = strlen(str);
  if(input_len > 63) {
    fprintf(stderr, "\ncannot have more than 32 fields in csv_string, or string malformed");
    exit(1);
  }

  for(size_t i=0; i<input_len; i++) {
    switch(str[i]) {
    case 's': d->dsl_str[i] = STRING;  ++d->len; break;
    case 'f': d->dsl_str[i] = FLOAT;   ++d->len; break;
    case 'i': d->dsl_str[i] = INTEGER; ++d->len; break;
    case 'b': d->dsl_str[i] = BOOL;    ++d->len; break;

    case '-': 
      break; // we skip delimiter and end of string

    default:
      fprintf(stderr, "\ntoken shouln't exist in dsl string");
      exit(1);
    }
  }
  return;
}

#endif


