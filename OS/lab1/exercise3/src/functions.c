#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Fills a deck of cards with all possible combinations of ranks, suits and
 * without the jokers. Suit and ranks are represented as enums
 *
 * @param deck A pointer to a deck of cards.
 */
void fillDeck(Card* deck) {
  int i = 0;
  // for every suit, create every rank (nested for-loop)
  for (int suit = SPADES; suit <= DIAMONDS; suit++) {
    for (int rank = ACE; rank <= KING; rank++) {
      deck[i].rank = rank;
      deck[i].suit = suit;
      i++;
    }
  }
}

/**
 * Fills a hand of cards with 5 randomly selected cards from a deck.
 *
 * @param hand A pointer to a hand of cards.
 * @param deck A pointer to a already FILLED deck of cards.
 */
void fillHand(Card* hand, Card* deck) {
  printf("FillHand\n");
  int seenIndex[52] = {0};

  srand(time(NULL));

  // generate 5 random cards from the deck and store it in hand
  for (int i = 0; i < 5; i++) {
    int randIndex = rand() % 52;
    if (!seenIndex[randIndex]) {
      // if we haven't seen the index before add it to the hand
      seenIndex[randIndex] = 1;  // mark it as seen
      hand[i] = deck[randIndex];
    } else {
      i--;  // we have seen it before, try again
    }
  }
}

/**
 * Evaluates a poker hand to determine its strength.
 *
 * @param hand A pointer to a hand of cards.
 * @return A string indicating the strength of the hand.
 */
const char* evaluateHand(Card* hand) {
  printf("Evaluating hand\n");

  // count rank and suits
  int rankCount[13] = {0};
  int suitCount[4] = {0};

  // count pairs
  int countPairs = 0;
  // check if isFlush
  int isFlush = 0;
  // check for three diferent suits
  int isThreeKind = 0;
  // check for four different suits
  int isFourKind = 0;
  // count consecutives ranks to check for straight
  int countConsecutive = 0;
  int isStraight = 0;

  for (int i = 0; i < 5; i++) {
    if (++rankCount[hand[i].rank - 1] == 2) countPairs++;

    if (++suitCount[hand[i].suit] == 5) isFlush = 1;
  }
  // check for consecutives and reset count when encounter something else
  // besides 1
  for (int i = 0; i < 13; i++) {
    if (rankCount[i] == 1)
      isStraight = ++countConsecutive == 5;
    else
      countConsecutive = 0;
  }

  // check for three of a kind or four of a kind
  for (int i = 0; i < 4; i++) {
    if (suitCount[i] == 3) isThreeKind = 1;
    if (suitCount[i] == 4) isFourKind = 1;
  }

  if (isFlush)
    return "Flush";
  else if (isStraight)
    return "Straight";
  else if (isFourKind)
    return "Four of a Kind";
  else if (isThreeKind)
    return "Three of a Kind";
  else if (countPairs == 2)
    return "Two Pairs";
  else if (countPairs == 1)
    return "Pairs";
  else
    return "None";
}

/**
 * Prints a hand of cards to the stdin.
 *
 * @param hand A pointer to a hand of cards.
 */
void printHand(Card* hand) {
  for (unsigned int i = 0; i < 5; i++) {
    // write the suit in the buffer
    switch (hand[i].suit) {
      case SPADES:
        printf("♤ ");
        break;
      case HEARTS:
        printf("♡ ");
        break;
      case CLUBS:
        printf("♧ ");
        break;
      case DIAMONDS:
        printf("♢ ");
        break;
    }
    // write the rank in the buffer
    switch (hand[i].rank) {
      case ACE:
        printf("A ");
        break;
      case JACK:
        printf("J ");
        break;
      case QUEEN:
        printf("Q ");
        break;
      case KING:
        printf("K ");
        break;
      default:
        printf("%d ", hand[i].rank);
        break;
    }
    // print and clear the buffer
    printf("\n");
  }
}