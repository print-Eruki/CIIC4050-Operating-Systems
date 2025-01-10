#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef enum { SPADES, HEARTS, CLUBS, DIAMONDS } Suit;

typedef enum {
  ACE = 1,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING
} Rank;

typedef struct {
  Suit suit;
  Rank rank;
} Card;

void fillDeck(Card* deck);

void fillHand(Card* hand, Card* deck);

const char* evaluateHand(Card* hand);

void printHand(Card* hand);

#endif
