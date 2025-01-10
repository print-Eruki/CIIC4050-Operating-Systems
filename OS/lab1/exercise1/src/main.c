#include <stdio.h>

#include "functions.h"

int main() {
  int N = 20;

  int randNumber = GenerateRandomNumber(N);

  int userGuess = GetUserGuess();

  int isGuessed = VerifyGuess(randNumber, userGuess);

  if (isGuessed) {
    printf("Number guessed corectly!\n");
  } else {
    printf("Number guessed incorrectly!\n");
  }

  return 0;
}
