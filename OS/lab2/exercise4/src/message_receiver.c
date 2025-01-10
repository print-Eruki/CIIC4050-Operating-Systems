#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define QUEUE_NAME "/msg_queue"
#define MAX_SIZE 256
#define MSG_STOP "exit"

/**
 * This program opens a message queue, receives messages from it,
 * converts and sum all the integers received, and finally prints the sum
 * and the execution time. 
 */
int main() {
  mqd_t mq;
  ssize_t bytes_read;

  struct mq_attr attr;

  // Initialize the queue attributes
  attr.mq_flags = 0;
  attr.mq_maxmsg = 7;
  attr.mq_msgsize = MAX_SIZE;
  attr.mq_curmsgs = 0;

  // Create the message queue
  mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);
  if (mq == (mqd_t)-1) {
    perror("mq_open");
    exit(1);
  }
  time_t startTime;
  time_t endTime;
  int firstIteration = 1;
  long long int sum = 0;
  while (1) {
    char buffer[MAX_SIZE];

    // Receive the message
    bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
    if (bytes_read == -1) {
      perror("mq_receive");
      exit(1);
    }

    // Check if the message is the stop message
    if (strncmp(buffer, MSG_STOP, strlen(MSG_STOP)) == 0) {
      break;
    }
    //convert the message into an int and add into sum
    int message = atoi(buffer);
    sum += message;

    if (firstIteration) {
      time(&startTime);
      firstIteration = 0;
    }
  }
  time(&endTime);

  // Close and unlink the message queue
  if (mq_close(mq) == -1) {
    perror("mq_close");
    exit(1);
  }

  if (mq_unlink(QUEUE_NAME) == -1) {
    perror("mq_unlink");
    exit(1);
  }

  printf("Total sum: %lld\n", sum);
  printf("Execution time: %f\n", difftime(endTime, startTime));

  return 0;
}