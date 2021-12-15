#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}


void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  for (int idx = 0; idx < origDeck.size - 1; idx++)
  {
    leftDeck[idx].size = idx + 1;
    rightDeck[idx].size = origDeck.size - leftDeck[idx].size;
    memcpy(leftDeck[idx].cards, origDeck.cards, leftDeck[idx].size * sizeof(origDeck.cards[0]));
    memcpy(rightDeck[idx].cards, origDeck.cards + leftDeck[idx].size, rightDeck[idx].size * sizeof(origDeck.cards[0]));
  }
}

//recursive function: check for terminating condition first
void card(CardDeck newDeck, int newCard, CardDeck leftDeck, int leftCard, CardDeck rightDeck, int rightCard, int round)
{
  if(leftCard == leftDeck.size)
  {
    while(rightCard < rightDeck.size)
    {
      newDeck.cards[newCard] = rightDeck.cards[rightCard];
      newCard++;
      rightCard++;
    }
    round--;
    if(round == 0)
    {
      printDeck(newDeck);
      return;
    }
    else
    {
      shuffle(newDeck, round);
      return;
    }

  }
  else if(rightCard == rightDeck.size)
  {
    while(leftCard < leftDeck.size)
    {
      newDeck.cards[newCard] = leftDeck.cards[leftCard];
      newCard++;
      leftCard++;
    }
    round--;
    if(round == 0)
    {
      printDeck(newDeck);
      return;
    }
    else
    {
      shuffle(newDeck, round);
      return;
    }
  }

  newDeck.cards[newCard] = leftDeck.cards[leftCard];
  card(newDeck, newCard + 1, leftDeck, leftCard + 1, rightDeck, rightCard, round);

  newDeck.cards[newCard] = rightDeck.cards[rightCard];
  card(newDeck, newCard + 1, leftDeck, leftCard, rightDeck, rightCard + 1, round);
}

void interleave(CardDeck leftDeck, CardDeck rightDeck, int round)
{
  int newCard = 0;
  int leftCard = 0;
  int rightCard = 0;

  CardDeck newDeck =
  {
    .size = leftDeck.size + rightDeck.size,
    .cards = {0}
  };

  card(newDeck, newCard, leftDeck, leftCard, rightDeck, rightCard, round);

}

void shuffle(CardDeck origDeck, int round)
{
  int countDeck = origDeck.size - 1;
  CardDeck * leftDeck = (CardDeck *) malloc(countDeck * sizeof(CardDeck));
  CardDeck * rightDeck = (CardDeck *) malloc(countDeck * sizeof(CardDeck));

  if (leftDeck == NULL || rightDeck == NULL) //if (!leftDeck || !rightDeck)
  {
    return;
  }

  divide(origDeck, leftDeck, rightDeck);

  for(int i = 0; i < countDeck; i++)
  {
    interleave(leftDeck[i], rightDeck[i], round);
  }

  free(leftDeck);
  free(rightDeck);

}
