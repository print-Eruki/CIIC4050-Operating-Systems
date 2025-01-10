#include <fcntl.h>
#include <functions.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
  SetNcurses();
  SetTimer();
  while (is_reading) {
    pause();
  }

  return 0;
}