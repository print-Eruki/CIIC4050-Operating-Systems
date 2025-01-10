#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  const char *device = "/dev/input/mice";  // Generic mouse device file
  int fd = open(device, O_RDONLY);
  if (fd == -1) {
    perror("Error opening device");
    return 1;
  }

  signed char data[3];

  printf("Listening for mouse events. Move the mouse or press buttons.\n");
  while (1) {
    if (read(fd, data, sizeof(data)) > 0) {
      int left = data[0] & 0x1;
      int right = data[0] & 0x2;
      int middle = data[0] & 0x4;
      int dx = data[1];
      int dy = data[2];

      printf("Left: %d, Right: %d, Middle: %d, dx: %d, dy: %d\n", left, right,
             middle, dx, dy);
    }
  }

  close(fd);
  return 0;
}