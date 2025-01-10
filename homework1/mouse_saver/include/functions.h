#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern int fd;
extern float mouse_x;
extern float mouse_y;

/**
 * @brief Reads mouse events and updates mouse coordinates.
 * 
 * Opens the mouse device file and listens for mouse events, updating the 
 * mouse_x and mouse_y coordinates based on the input data.
 */
void ReadMouse();

/**
 * @brief Closes the file and device descriptor on receiving a signal.
 * 
 * This function is called when a signal is received, closing the file and 
 * device descriptor, and then exiting the program.
 * 
 * @param signum The signal number.
 */
void CloseFile(int signum);

/**
 * @brief Writes the mouse coordinates to a file.
 * 
 * Writes the provided mouse coordinates (x and y) to the file.
 * 
 * @param x The x-coordinate of the mouse.
 * @param y The y-coordinate of the mouse.
 */
void WriteMouseData(int x, int y);

#endif