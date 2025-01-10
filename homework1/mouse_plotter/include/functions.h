#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>

extern FILE* fd;
extern int x;
extern int y;
extern int is_reading;

/**
 * @brief Plots the mouse coordinates on the screen using ncurses.
 * 
 * Reads the mouse coordinates from the file and plots them on the screen.
 */
void PlotMouse();

/**
 * @brief Sets up a timer to periodically call the PlotMouse function.
 * 
 * Opens the mouse data file and sets up a real-time timer to call PlotMouse 
 * at regular intervals.
 */
void SetTimer();

/**
 * @brief Initializes the ncurses library.
 * 
 * Sets up the ncurses library for use, disabling echo and hiding the cursor.
 */
void SetNcurses();


#endif 