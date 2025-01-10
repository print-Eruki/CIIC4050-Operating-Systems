#include <fcntl.h>
#include <functions.h>
#include <linux/input.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  //map the sigint signal to a function named CloseFile
  struct sigaction sa;
  sa.sa_handler = CloseFile;
  sigaction(SIGINT, &sa, NULL);

  ReadMouse();
  
  return 0;
}