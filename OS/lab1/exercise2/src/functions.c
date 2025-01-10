#include "functions.h"

#include <stdio.h>

/**
 * Prints a `Time` structure in HH:MM:SS format.
 *
 * @param t A `Time` structure to be printed.
 */
void PrintTime(Time t) {
  printf("%02d:%02d:%02d\n", t.hour, t.minutes, t.seconds);
}

/**
 * Prompts the user to enter a valid time in 24-hour format and returns a `Time`
 * structure.
 *
 * @return A `Time` structure representing the entered time.
 */
struct Time GetTime() {
  int userHour;
  int userMin;
  int userSec;

  while (1) {
    printf("Enter the hour in 24 format: \n");
    scanf("%d", &userHour);
    if (userHour <= 24 && userHour >= 0) break;
  }

  while (1) {
    printf("Enter the minutes: \n");
    scanf("%d", &userMin);
    if (userMin <= 60 && userMin >= 0) break;
  }

  while (1) {
    printf("Enter the seconds: \n");
    scanf("%d", &userSec);
    if (userSec <= 60 && userSec >= 0) break;
  }

  Time time = {.hour = userHour, .minutes = userMin, .seconds = userSec};
  return time;
}