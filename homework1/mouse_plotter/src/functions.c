#include <functions.h>
#include <ncurses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

FILE* fd;
int x;
int y;
int is_reading = 1;

void PlotMouse() {
  
  if (fread(&x, sizeof(int), 1, fd) >=1 && 
      fread(&y, sizeof(int), 1, fd) >= 1) {
    clear();
    mvprintw(y, x, "*");
    refresh();
  } else {
    printf("Exiting\n");
    is_reading = 0;
  }
}

void SetTimer() {
  fd = fopen("mouse_data.dat", "r");
  timer_t timer_id;
  timer_create(CLOCK_REALTIME, NULL, &timer_id);
  struct sigaction action;
  action.sa_handler = PlotMouse;
  action.sa_flags = 0;
  sigaction(SIGALRM, &action, NULL);

  struct itimerspec timer_params;
  timer_params.it_value.tv_sec = 0;
  timer_params.it_value.tv_nsec = 10 * 1000000;
  timer_params.it_interval.tv_sec = 0;
  timer_params.it_interval.tv_nsec = 10 * 1000000;
  timer_settime(timer_id, 0, &timer_params, NULL);
}

void SetNcurses() {
  initscr();
  noecho();
  curs_set(0);
}