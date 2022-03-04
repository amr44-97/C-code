#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LIST 40

void string_split(char *old_list, char *new_list[MIN_LIST]) {
  // cloned the const char into chunks ended by \0
  // char  old_list[28]={"name family age job salary"}; // type cahr *

  char *ptr_listclone;
  ptr_listclone = &old_list[0];
  new_list[0] = ptr_listclone;

  int i = 0;
  int x = 0;

  while (old_list[i] != '\0') {
    if (old_list[i] == ' ' || old_list[i] == '\n' || old_list[i] == ',') {
      old_list[i] = '\0';
      ptr_listclone = &old_list[i + 1];
      new_list[x + 1] = ptr_listclone;
      x++;
    }
    i++;
  }
}

int main(int argc, char **argv) {
  FILE *file;
  file = fopen("./basic_parse.ara", "r");
  fseek(file, 0, SEEK_END);
  int file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *file_content = (char *)malloc(sizeof(char) * file_size + 1);
  fread(file_content, 1, file_size, file);
  file_content[file_size] = '\0';
  printf("\n--------------------------------------------\n");
  char *new_list[MIN_LIST] = {NULL};

  string_split(file_content, new_list);

  printf("size of list = %ld\n", sizeof(new_list));

  printf("{");
  for (int i = 0; i < MIN_LIST; ++i) {
    if (new_list[i] == NULL) {
      break;
    }
    if (*new_list[i] == '\0') {
      continue;
    }
    printf(" \"%s\",", new_list[i]);
  }
  printf("}\n");

  return 0;
}
