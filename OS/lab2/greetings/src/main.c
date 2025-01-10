#include <stdio.h>
#include <unistd.h>
#include <wait.h>


int main () {
  printf("hello there, I'm process %d\n", getpid());
  sleep(10);
  printf("I'm done, bye!\n");
  return 0;
}