#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main() {
  int deckSize = 52;
  int handSize = 5;

  Card* deck = (Card*)malloc(deckSize * sizeof(Card));
  Card* straightHand = (Card*)malloc(5 * sizeof(Card));
  for (int i = 0; i < 5; i++) {
    straightHand[i].rank = FIVE + i;
    straightHand[i].suit = i % 4;
  }

  Card* fourOfAKind = (Card*)malloc(handSize * sizeof(Card));
  fourOfAKind[0].suit = SPADES;
  fourOfAKind[1].suit = SPADES;
  fourOfAKind[2].suit = SPADES;
  fourOfAKind[3].suit = SPADES;
  fourOfAKind[4].suit = HEARTS;

  fourOfAKind[0].rank = ACE;
  fourOfAKind[1].rank = ACE;
  fourOfAKind[2].rank = ACE;
  fourOfAKind[3].rank = ACE;
  fourOfAKind[4].rank = ACE;

  Card* hand = (Card*)malloc(handSize * sizeof(Card));

  fillDeck(deck);

  fillHand(hand, deck);
  printf("Hand:\n");
  printHand(hand);
  printf("%s\n", evaluateHand(hand));

  printf("Straight Hand: \n");
  printHand(straightHand);
  printf("%s\n", evaluateHand(straightHand));

  printf("Four of a kind hand: \n");
  printHand(fourOfAKind);
  printf("%s\n", evaluateHand(fourOfAKind));

  return 0;
}
