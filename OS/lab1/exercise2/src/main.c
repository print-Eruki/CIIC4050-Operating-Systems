#include <stdio.h>

#include "functions.h"

int main() {
  Time time = {.hour = 15, .minutes = 5, .seconds = 25};

  PrintTime(time);

  time = GetTime();

  PrintTime(time);

  return 0;
}
