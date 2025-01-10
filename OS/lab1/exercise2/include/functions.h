#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Time {
  int hour;
  int minutes;
  int seconds;
} Time;

void PrintTime(Time t);

struct Time GetTime();

#endif
