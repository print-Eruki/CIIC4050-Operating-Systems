#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

/**
 * This program creates a hierarchy of processes using fork(). The main process
 * creates three child processes, each of which creates two more child processes (grandchildren).
 * Each grandchild process executes an external program `greetings`, and the parent process waits 
 * for all child processes to terminate before exiting.
 *
 */
int main() {

  int status = 0;
  pid_t wpid;

  for (int i = 0; i < 3; i++) {
    int pid = fork();

    if (pid == 0) {
      //log the child pid and parent pid
      fprintf(stdout, "I'm a child, and my pid is: %d\n", getpid());

      //create two new child processes per child
      for (int j = 0; j < 2; j++) {
        int childPid = fork();
        if (childPid == 0) {
          //execute greetings exe, we need to step out from src and into build
          execl("../build/greetings", "../build/greetings", (char*)NULL);
          exit(0);
        }
      }
      //children processes waiting for grandchildrens processes
      while ((wpid = wait(&status)) > 0)
        ;
      exit(0);
    }
  }

  //parent process, wait for the child to finish
  while ((wpid = wait(&status)) > 0)
    ;

  return 0;
}