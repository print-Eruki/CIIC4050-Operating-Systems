#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

#define MAX_LENGTH 100

int main() {
  printf("Replace:\n");

  // I know that I might allocate more memory than needed and might end up not
  // using at all
  char* dst = (char*)malloc(MAX_LENGTH * sizeof(char));
  char* src = "hola mundo";
  char find = 'o';
  char replacement = 'a';
  Replace(src, dst, find, replacement);
  printf("%s\n", dst);
  free(dst);

  printf("Insert:\n");

  dst = (char*)malloc(MAX_LENGTH * sizeof(char));
  src = "Hola mundo";
  find = 'o';
  char* ins = "ronda";
  Insert(src, dst, find, ins);

  printf("%s", dst);

  // while (1) {
  //   printf("Enter a string:\n");
  //   scanf("%s", src);
  //   printf("Enter the char to find in the string:\n");
  //   scanf("%c", &find);
  //   printf("Enter the char to replace find:\n");
  //   scanf("%c", &replacement);
  //   Replace(src, dst, find, replacement);
  //   printf("%s", dst);
  //   int choice;
  //   printf("Again? (1 - yes, 0 - no):\n");
  //   scanf("%d", &choice);
  //   if (choice) break;
  // }

  return 0;
}