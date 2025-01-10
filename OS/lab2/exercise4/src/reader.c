#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

#define SHM_SIZE 1000000 * sizeof(int)  // Shared memory size

#define SEM_PRODUCER "/producer"
#define SEM_CONSUMER "/consumer"

int main() {

  key_t key = ftok("/tmp", 65);

  if (key == -1) {
    perror("ftok");
    return 1;
  }

  sem_t* semaphore_producer = sem_open(SEM_PRODUCER, O_CREAT, 0666, 0);
  if (semaphore_producer == SEM_FAILED) {
    perror("error opening producer semaphore");
    exit(EXIT_FAILURE);
  }

  sem_t* semaphore_consumer = sem_open(SEM_CONSUMER, O_CREAT, 0666, 1);
  if (semaphore_consumer == SEM_FAILED) {
    perror("error opening consumer semaphore");
    exit(EXIT_FAILURE);
  }

  //init a shared memory block for 1 million integers
  int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmget failed");
    exit(EXIT_FAILURE);
  }

  // map the block into the process adress space
  int* data = (int*)shmat(shmid, NULL, 0);

  if (data == (int*)-1) {
    perror("shmat failed");
    exit(EXIT_FAILURE);
  }
  time_t startTime;
  time_t endTime;
  long long sum = 0;
  for (int i = 0; i < 1000000; i++) {
    //wait for the producer
    sem_wait(semaphore_producer);
    //if it's the first iteration then get the initial time
    if (i == 0)
      time(&startTime);
    sum += data[i];
    //signal consumer has processed
    sem_post(semaphore_consumer);
  }
  //get the endtime
  time(&endTime);

  printf("Total sum is: %lld\n", sum);
  printf("Execution time: %f\n", difftime(endTime, startTime));

  sem_close(semaphore_consumer);
  sem_close(semaphore_producer);

  // Detach from shared memory
  shmdt(data);

  return 0;
}