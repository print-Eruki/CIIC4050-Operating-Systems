#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define QUEUE_NAME "/msg_queue"
#define MAX_MSG_SIZE 256
#define MSG_STOP "exit"

/**
 * This program creates a message queue, sends a integers from zero to one million,
 * and then sends a stop message to signal the end of transmission.
 */
int main() {

  mqd_t mq;
  struct mq_attr attr;

  attr.mq_flags = 0;
  attr.mq_maxmsg = 1000000;  //One million messages [0, 1000000)
  attr.mq_msgsize = MAX_MSG_SIZE;
  attr.mq_curmsgs = 0;

  mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);

  for (int i = 0; i <= 1000000; i++) {
    char message[MAX_MSG_SIZE];
    sprintf(message, "%d", i);

    int status = mq_send(mq, message, strlen(message), 0);
    if (status == -1) {
      perror("mq_send");
      exit(1);
    }
    printf("Sent message: %s\n", message);
  }

  //stop the receiver
  int status = mq_send(mq, MSG_STOP, sizeof(MSG_STOP), 0);
  if (status == -1) {
    perror("mq_send");
    exit(1);
  }

  mq_close(mq);

  return 0;
}