#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//defined counter as a global variable
long int counter = 0;
//1 to go upwards, -1 to go downwards
int direction = 1;

void counterReset(int num) {
  write(STDOUT_FILENO, "Resetting counter\n", 19);
  counter = 0;
}

void changeDirection(int num) {
  write(STDOUT_FILENO, "Changing direction\n", 20);
  direction = direction * -1;
}

/**
 *
 * Sets up signal handlers for SIGUSR1 and SIGUSR2, then enters an infinite loop
 * that increments or decrements a counter and prints its value every second.
 *
 */
int main() {
  struct sigaction sa;
  sa.sa_handler = counterReset;
  sigaction(SIGUSR1, &sa, NULL);

  struct sigaction sa2;
  sa2.sa_handler = changeDirection;
  sigaction(SIGUSR2, &sa2, NULL);

  printf("I'm process %d\n", getpid());

  while (1) {
    printf("I'm counting, and my count is %ld\n", counter);
    counter = counter + direction;
    //sleep for one second
    sleep(1);
  }

  return 0;
}