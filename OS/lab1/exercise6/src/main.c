#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

#define MAX_HEIGHT 3  // sentences
#define MAX_WIDTH 20  // 20 chars width max

int main() {
  char** text = (char**)malloc((MAX_HEIGHT + 1) * sizeof(char*));
  text[MAX_HEIGHT] = NULL;  // NULL terminator
  printf("Asking the user for 3 sentences\n");
  for (int i = 0; i < MAX_HEIGHT; i++) {
    char* sentence = (char*)malloc(MAX_WIDTH * sizeof(char));
    printf("Enter sentence %d.: (Limit: %d)", i + 1, MAX_WIDTH);
    fgets(sentence, MAX_WIDTH, stdin);
    text[i] = sentence;
  }

  while (1) {
    int choice = 0;
    printf("1. Align to the left\n");
    printf("2. Align to the right\n");
    printf("3. Align to the justify\n");
    printf("0. Exit the program\n");
    scanf("%d", &choice);
    if (choice == 1)
      alignLeft(text);
    else if (choice == 2)
      alignRight(text);
    else if (choice == 3)
      justify(text);
    else if (choice == 0)
      break;
    // any other input, the program will ask again
  }

  return 0;
}