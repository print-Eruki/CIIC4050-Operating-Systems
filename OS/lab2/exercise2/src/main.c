#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

/**
 * @brief Main function for a simple shell-like command executor.
 *
 * Continuously prompts for and executes user commands. Supports multiple
 * commands separated by semicolons. Exits on 'exit' command.
 *
 * @return 0 on normal termination
 */
int main() {
  char* commands = (char*)malloc(250 * sizeof(char));
  while (1) {  // infinite loop until 'q'
    char* args;

    fprintf(stdout, "Enter a command: ");

    fgets(commands, 250, stdin);

    //remove the newline character from the end of the command
    commands[strcspn(commands, "\n")] = '\0';

    //if the command is exit, terminate the program
    if (strcmp(commands, "exit") == 0) {
      return 0;
    }

    strcat(commands, ";");
    args = strtok(commands, ";");

    while (args != NULL) {
      int pid = fork();
      if (pid == 0) {
        char* arglist[10];
        int i = 0;
        //delimited by spaces, so use strtok to get the command and args
        arglist[i] = strtok(args, " ");
        while (arglist[i] != NULL) {
          i++;
          arglist[i] = strtok(NULL, " ");
        }
        execvp(arglist[0], arglist);
        //exit in case the command fails
        exit(0);
      } else {
        wait(NULL);
        //get the next command
        args = strtok(NULL, ";");
      }
    }
  }
  free(commands);
  return 0;
}