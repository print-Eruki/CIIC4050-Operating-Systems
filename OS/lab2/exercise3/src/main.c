#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Displays a list of PIDs and prompts the user to select one.
 *
 * @param pids Array of process IDs to display
 * @param count Number of PIDs in the array
 * @return The selected PID, or -1 if an error occurs (unreachable in current implementation)
 */
int displayOptions(int* pids, int count) {
  //show all the pids given earlier as arguments
  for (int i = 0; i < count; i++) {
    printf("%d. %d\n", i + 1, pids[i]);
  }

  int choice;

  while (1) {

    printf("Enter the PID you want to choose (1 - %d): ", count);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= count) {
      //return the PID of the chosen process
      return pids[choice - 1];
    } else {
      printf("Invalid choice, try again\n");
    }
  }

  return -1;  //dummy return
}

/**
 * @brief Removes a specific PID from an array of PIDs.
 *
 * @param pids Array of process IDs
 * @param count Number of PIDs in the array
 * @param pid The process ID to remove
 */
void removePid(int* pids, int count, int pid) {
  //remove the pid from the list of pids
  for (int i = 0; i < count; i++) {
    if (pids[i] == pid) {
      for (int j = i; j < count - 1; j++) {
        pids[j] = pids[j + 1];
      }
      break;
    }
  }
}

/**
 *
 * Provides a menu-driven interface to control multiple infinite-counter processes.
 * Options include stopping, continuing, resetting, changing direction, and killing processes.
 *
 * @param argc number of pids
 * @param argv pids of infinite-counter processes
 */
int main(int argc, char** argv) {
  //the argv are the infinite-counter processes pid
  int* pids = (int*)malloc((argc - 1) * sizeof(int));
  for (int i = 1; i < argc; i++) {
    pids[i - 1] = atoi(argv[i]);
  }
  argc--;

  while (1) {

    if (argc == 0) {
      printf("No infinite-counter processes running\n");
      return 0;
    }

    int choice;
    //Show the options
    printf("1. Stop a specific infinite-counter process\n");
    printf("2. Continue a specific infinite-counter process\n");
    printf("3. Reset the counter for a specific infininte-counter process\n");
    printf(
        "4. Change the counting direction of a specific infinite-counter "
        "process\n");
    printf("5. Kill a specific infinite-counter process\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);
    if (choice == 6) {
      break;
    }

    int pid = displayOptions(pids, argc);

    switch (choice) {
      case 1:
        //Stop a specific infinite-counter process
        kill(pid, SIGSTOP);
        break;
      case 2:
        //Continue a specific infinite-counter process
        kill(pid, SIGCONT);
        break;
      case 3:
        //Reset the counter for a specific infininte-counter process
        kill(pid, SIGUSR1);
        break;
      case 4:
        //Change the counting direction of a specific infinite-counter process
        kill(pid, SIGUSR2);
        break;
      case 5:
        //Kill a specific infinite-counter process
        kill(pid, SIGTERM);
        removePid(pids, argc, pid);
        argc--;
        break;
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}