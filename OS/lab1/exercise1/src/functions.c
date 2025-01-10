#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Generates a random integer within a specified range.
 *
 * @param N The upper bound of the random number range (inclusive).
 * @return A random integer between 0 and `N`, inclusive.
 */
int GenerateRandomNumber(int N) {
  // increase the variability by changing the seed
  srand(time(NULL));

  int randomNumber = rand();

  printf("Generating random number\n");

  return randomNumber % (N + 1);
}

/**
 * Prompts the user to enter an integer and returns the entered value.
 *
 * @return The integer entered by the user.
 */
int GetUserGuess() {
  int userGuess;

  printf("Enter your guess: \n");

  scanf("%d", &userGuess);

  return userGuess;
}

/**
 * Compares a generated random number with a user's guess and determines if they
 * match.
 *
 * @param randomNumber The generated random number.
 * @param userGuess The user's guess.
 * @return 1 if the `randomNumber` and `userGuess` are equal, 0 otherwise.
 */
int VerifyGuess(int randomNumber, int userGuess) {
  return randomNumber == userGuess;
}
