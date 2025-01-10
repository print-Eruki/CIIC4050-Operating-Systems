#include <fcntl.h>
#include <math.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 2000 * sizeof(double) // Shared memory size

#define SEM_GENERATOR "/generator"
#define SEM_ANALYZER "/analyzer"
#define SEM_PLOT "/plot"

int main() {

  key_t key = ftok("/tmp", 65);

  sem_t *semaphore_generator = sem_open(SEM_GENERATOR, O_CREAT, 0666, 0);

  sem_t *semaphore_analyzer = sem_open(SEM_ANALYZER, O_CREAT, 0666, 0);

  sem_t *semaphore_plot = sem_open(SEM_PLOT, O_CREAT, 0666, 0);
  // init a shared memory block for 1 million integers
  int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

  // map the block into the process adress space
  double *data = (double *)shmat(shmid, NULL, 0);
  int j = 0;
  printf("Analyzer started\n");

  for (int i = 999; i >= 0; i--) {
    sem_wait(semaphore_generator);
    // calculate the sin from the shmid and store it at the last block

    data[i + 1000] = sin(data[j]);
    printf("Analyzer calculated %f\n", data[i + 1000]);
    j++;
    sem_post(semaphore_analyzer);
    sem_post(semaphore_plot);
  }

  sem_close(semaphore_analyzer);
  sem_close(semaphore_generator);
  sem_close(semaphore_plot);

  // Detach from shared memory
  shmdt(data);

  return 0;
}