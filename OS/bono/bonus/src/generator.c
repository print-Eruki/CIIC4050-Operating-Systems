// writer.c
#include <fcntl.h> // For O_* constants
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 2000 * sizeof(double) // Shared memory size

#define SEM_GENERATOR "/generator"
#define SEM_ANALYZER "/analyzer"

int main(int argc, char *argv[]) {
  key_t key;
  int shmid;
  double *data;

  // Create a unique key for the shared memory
  key = ftok("/tmp", 65);

  if (key == -1) {
    perror("ftok");
    exit(EXIT_FAILURE);
  }

  sem_t *semaphore_generator = sem_open(SEM_GENERATOR, O_CREAT, 0666, 0);

  sem_t *semaphore_analyzer = sem_open(SEM_ANALYZER, O_CREAT, 0666, 0);

  // Create a shared memory segment
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

  // Attach to the shared memory segment
  data = (double *)shmat(shmid, NULL, 0);

  printf("Writing into the shared memory\n");
  // Write to shared memory
  int j = 0;
  for (double i = 0.0; i < 19.98; i += 0.02) {
    printf("Writer: Writing to shared memory: ");
    data[j] = i;
    printf("%f", data[j]);
    printf("\n");
    j++;
    sem_post(semaphore_generator);
    sem_wait(semaphore_analyzer);
  }

  sem_close(semaphore_analyzer);
  sem_close(semaphore_generator);

  // Detach from shared memory
  shmdt(data);

  return 0;
}