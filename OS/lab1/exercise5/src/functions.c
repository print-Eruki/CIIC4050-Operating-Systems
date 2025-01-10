#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * Converts a single-digit integer to its word representation.
 *
 * @param num The single-digit integer to be converted.
 * @return A pointer to a string containing the word representation of the input
 * integer.
 */
const char* convert(int num) {
  char* toStr[10] = {"Zero ", "One ", "Two ",   "Three ", "Four ",
                     "Five ", "Six ", "Seven ", "Eight ", "Nine "};

  return toStr[num];
}

/**
 * Converts an integer to a string representation.
 * Saves the integer in an array with size log10(num) + 1
 * iterate over it and convert it using 'hashing'
 * returns a pointer of the string
 *
 *
 * @param num The integer to be converted.
 * @return A dynamically allocated string containing the character
 * representation of the input integer.
 */
char* numToStr(int num) {
  // we are also going to calculate the length based on the length of the str +
  // 1 with space
  int numSize = log10((float)num) + 1;
  int nums[numSize];
  int length = 0;
  int i = numSize - 1;
  while (num) {
    length += strlen(convert(num % 10)) + 1;
    nums[i--] = num % 10;
    num /= 10;
  }
  // we end up with one extra space that is going to be used for the null
  // terminator
  char* dst = (char*)malloc(length * sizeof(char));
  dst[length] = '\0';
  // do the same with reverseNum but now added consecutive to dst
  i = 0;
  int j = 0;
  for (; i < numSize; i++) {
    const char* convertedNum = convert(nums[i]);
    strcpy(dst + j, convertedNum);
    j += strlen(convertedNum);
  }
  return dst;
}