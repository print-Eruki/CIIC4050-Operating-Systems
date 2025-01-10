#include <fcntl.h>
#include <functions.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define screen_width 1028
#define screen_height 800

FILE* file;
int fd;
float mouse_x = screen_width / 2;
float mouse_y = screen_height / 2;

void ReadMouse() {
  const char* device = "/dev/input/mice";  // Generic mouse device file
  file = fopen("mouse_data.dat", "wb");
  fd = open(device, O_RDONLY);
  if (fd == -1) {
    perror("Error opening device");
    return;
  }

  signed char data[3];

  printf("Listening for mouse events. Move the mouse or press buttons.\n");
  while (1) {
    if (read(fd, data, sizeof(data)) > 0) {
      int dx = data[1];
      int dy = data[2];

      mouse_x += dx;
      mouse_y += dy;

      if (mouse_x < 0)
        mouse_x = 0;
      if (mouse_x > screen_width)
        mouse_x = screen_width;
      if (mouse_y < 0)
        mouse_y = 0;
      if (mouse_y > screen_height)
        mouse_y = screen_height;

      float term_x = (mouse_x / screen_width) * 100;
      float term_y = (mouse_y / screen_height) * 25;

      WriteMouseData((int)term_x, (int)term_y);

      printf("mouse_x: %.2f, mouse_y: %.2f\n", mouse_x, mouse_y);
    }
  }
}

void CloseFile(int signum) {
  if (fd != -1) {
    close(fd);
  }
  if (file != NULL) {
    fclose(file);
    printf("File closed.\n");
  }
  exit(0);
}

void WriteMouseData(int x, int y) {
  if (file == NULL) {
    perror("Error opening file");
    return;
  }
  printf("%d %d\n", x, y);
  fwrite(&x, sizeof(int), 1, file);
  fwrite(&y, sizeof(int), 1, file);
}