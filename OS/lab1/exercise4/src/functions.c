#include "functions.h"

#include <string.h>

/**
 * Replaces all occurrences of a character in a string.
 *
 * @param src The source string.
 * @param dst The destination string.
 * @param find The character to be replaced.
 * @param replacement The character to replace the `find` character with.
 */
void Replace(char* src, char* dst, char find, char replacement) {
  unsigned int i = 0;
  for (; src[i] != '\0'; i++) {
    if (src[i] == find)
      dst[i] = replacement;
    else
      dst[i] = src[i];
  }
  // add the null termination into the dst
  dst[i] = '\0';
}

/**
 * Inserts a string at every occurrence of a character in a string.
 *
 * @param src The source string.
 * @param dst The destination string.
 * @param find The character to be replaced.
 * @param ins The string to be inserted.
 */
void Insert(char* src, char* dst, char find, char* ins) {
  int idx = 0;
  for (unsigned int i = 0; src[i] != '\0'; i++) {
    if (src[i] == find) {
      dst[idx++] = src[i];
      strcpy(dst + idx, ins);
      idx += strlen(ins);
    } else
      dst[idx++] = src[i];
  }
}