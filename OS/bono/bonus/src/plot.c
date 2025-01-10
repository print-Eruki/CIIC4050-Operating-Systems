#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 2000 * sizeof(double) // Shared memory size

#define SEM_ANALYZER "/analyzer"
#define SEM_PLOT "/plot"

int main() {

  key_t key = ftok("/tmp", 65);

  sem_t *semaphore_analyzer = sem_open(SEM_ANALYZER, O_CREAT, 0666, 0);

  sem_t *semaphore_plot = sem_open(SEM_PLOT, O_CREAT, 0666, 0);
  // init a shared memory block for 1 million integers
  int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);

  // map the block into the process adress space
  double *data = (double *)shmat(shmid, NULL, 0);
  printf("plot has started\n");
  for (int i = 0; i < 1000; i++) {
    sem_wait(semaphore_plot);
    printf("Data: %f, Sin: %f", data[i], data[i + 1000]);
  }

  sem_close(semaphore_analyzer);
  sem_close(semaphore_plot);

  // Detach from shared memory
  shmdt(data);

  return 0;
}