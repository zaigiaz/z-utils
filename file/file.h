#ifndef FILE_H
#define FILE_H

static void buf_slurp(strbuf * buf, const char *f_name)

// slurp up file contents, one 4kb chunk at a time.
static void buf_slurp(strbuf * buf, const char *f_name) 
{
  FILE *fp;
  fp = fopen(f_name, "rb");

  fseek(fp, 0L, SEEK_END);
  u64 file_size = ftell(fp);
  rewind(fp);

  int c, count=0;
  while((c = fgetc(fp)) != EOF) {
  buf->data[count++] = c;
  }
  fclose(fp);
  return;
}


#endif
