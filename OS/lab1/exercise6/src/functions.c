#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 20  // 20 chars width max

/**
 * Aligns text to the left.
 *
 * Removes leading and consecutive spaces from each line and adds extra spaces
 * at the end to ensure equal width.
 *
 * @param text A pointer to an array of strings representing the text to be
 * aligned.
 */
void alignLeft(char** text) {
  for (unsigned int i = 0; text[i] != NULL; i++) {
    // eliminating leading spaces
    while (text[i][0] == ' ') strcpy(text[i], text[i] + 1);

    // leaving one space between words
    for (unsigned int j = 1; text[i][j] != '\0'; j++) {
      if (text[i][j - 1] == ' ' && text[i][j] == ' ') {
        strcpy(text[i] + j - 1, text[i] + j);
        j--;
      }
    }

    int extraSpaces = MAX_WIDTH - strlen(text[i]);
    printf("%s%*s\n", text[i], extraSpaces, "");
  }
}

/**
 * Aligns text to the right.
 *
 * Removes leading, trailing, and consecutive spaces from each line and adds
 * extra spaces at the beginning to ensure equal width.
 *
 * @param text A pointer to an array of strings representing the text to be
 * aligned.
 */
void alignRight(char** text) {
  for (unsigned int i = 0; text[i] != NULL; i++) {
    // same as align left, eliminate the leading spaces
    while (text[i][0] == ' ') strcpy(text[i], text[i] + 1);

    // in this case we also need to eliminate trailing spaces in the sentence
    int length = strlen(text[i]);
    while (text[i][length - 1] == ' ') {
      text[i][length - 1] = '\0';  // mark it as the end
      length -= 1;
    }

    // leaving one space between words
    for (unsigned int j = 1; text[i][j] != '\0'; j++) {
      if (text[i][j - 1] == ' ' && text[i][j] == ' ') {
        strcpy(text[i] + j - 1, text[i] + j);
        j--;
      }
    }
    int leadingSpaces = MAX_WIDTH - (strlen(text[i]) + 1);
    printf("%*s%s\n", leadingSpaces, " ", text[i]);
  }
}

/**
 * Justifies text by aligning it to both left and right margins.
 *
 * Removes leading, trailing, and consecutive spaces from each line and adds
 * extra spaces between words to ensure equal width.
 *
 * @param text A pointer to an array of strings representing the text to be
 * justified.
 */
void justify(char** text) {
  for (unsigned int i = 0; text[i] != NULL; i++) {
    while (text[i][0] == ' ') {
      strcpy(text[i], text[i] + 1);
    }
    while (text[i][strlen(text[i]) - 1] == ' ') {
      text[i][strlen(text[i]) - 1] = '\0';
    }

    for (int j = 1; text[i][j] != '\0'; j++) {
      if (text[i][j - 1] == ' ' && text[i][j] == ' ') {
        strcpy(text[i] + j - 1, text[i] + j);
        j--;
      }
    }

    // now we have to calculate the in-between words and border spaces
    int spaces = MAX_WIDTH - strlen(text[i]);  // between spaces
    int borderSpace = spaces / 2;

    printf("%*s%s%*s\n", borderSpace, " ", text[i], borderSpace, " ");
  }
}

/**
 * Prints an array of strings to the standard output.
 *
 * @param text A pointer to an array of strings to be printed.
 */
void printText(char** text) {
  for (unsigned int i = 0; text[i] != NULL; i++) {
    printf("%s", text[i]);
  }
}