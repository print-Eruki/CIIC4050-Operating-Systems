#include <stdio.h>

#include "functions.h"

int main() {
  int num = 11528;

  printf("Number: %d\n", num);
  const char* str = numToStr(num);
  printf("%s\n", str);
  while (1) {
    printf("Enter a number:");
    scanf("%d", &num);
    printf("To string: %s\n", numToStr(num));
    printf("Again? (1 - Yes, 0 - No):");
    int choice = 0;
    scanf("%d", &choice);
    if (!choice) break;
  }

  return 0;
}