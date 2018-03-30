/**********************************************
* CardSet.cpp - Contains implementation of class CardSet
* <name, studNo, login, date completed, etc>
***********************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "CardSet.h"
using namespace std;

const bool debug = true;

/*************** CONSTRUCTORS ***************/

/* Default constructor sets up 0 cards using member initialization. */
CardSet::CardSet() : nCards(0), Card(NULL) { }

/* Initialising constructor */
CardSet::CardSet(int n)
{
    Card = new int[n];
    nCards = n;

    for (int i=0; i < n; i++) Card[i] = (i>=52) ? i%52 : i;
}

/*************** DESTRUCTOR ***************/
CardSet::~CardSet()
{
    int *Tmp;
    if (Card != NULL) {
        Tmp = Card;
        Card = NULL;
        delete [] Tmp;
    }
}

/*************** MUTATORS ***************/

/* Returns the first card in the set and reallocates memory for a new set with 1 less card. */
int CardSet::Deal()
{
    if (Card == NULL) {
        cout<<"[ERROR] The Card set is empty."<<endl;
        exit(1);
    }

    int *CardPtr;
    int DealCard = Card[0];
    int *NewCards = new int[--nCards];
    for (int i=1; i <= nCards; i++) NewCards[i-1] = Card[i];
    delete [] Card;
    Card = NewCards;
    return DealCard;
}

/* This function deals two hands into the two CardSet arguments passed.
 * The number of cards to be placed into each hand is the first argument.
 * The cards should be removed from the current set one at a time, placing
 * the cards into alternate hands. For example. if the current set held 2S,
 * 3S, 4S, 5S, 6S, 7S (the integers 0 to 5) and we had to deal 3 cards,
 * then the two hands would get 2S, 4S, 6S (integers 0, 2, 4) and 3S, 5S,
 * 7S (1, 3, 5) respectively. The two hands may already have cards in them,
 * and the additional cards will require new memory. Do not create new memory
 * more often than is required. Remember that the current set has to be reduced
 * in size as well. If there aren't enough cards in the current set to perform
 * the deal, print an error message and terminate.
*/
void Deal(int n, CardSet& Set1, CardSet& Set2)
{

}

void Deal(int n, CardSet& Set1, CardSet& Set2, CardSet& Set3, CardSet& Set4)
{

}

// Function to add a card to the current hand.
void CardSet::AddCard(int i)
{
    int k=0;
    nCards += 1;
    // Dynamic realloc of array
    int *NewCards = new int[nCards];
    NewCards[0] = i;

    for (int j=0; j < nCards; j++) NewCards[k++] = Card[j];

    int *TmpPtr;
    TmpPtr = Card;
    Card = NULL;
    delete [] TmpPtr;
    Card = NewCards;
}

/* This function rearranges the cards in the set in a random manner. */
void CardSet::Shuffle()
{
    int j=0;
    srand(time(NULL));
    for (int i=0; i < nCards; i++) {
        j = rand() % nCards - 1;

        if (i != j) {
            int TmpCard;
            TmpCard = Card[i];
            Card[i] = Card[j];
            Card[j] = TmpCard;
        }
    }
}

/* This function takes the current set and the set provided as an argument and makes the
 * current set contain all the cards from the two sets, with cards alternating from each
 * set as far as possible. After this function the argument set will be empty. */
void CardSet::MergeShuffle(CardSet& Set)
{
    int NewCardSz = nCards + Set.Size();  // Maintain a separate counter
    int *NewCards = new int[NewCardSz];  // Alloc memory for superset of Cards

    int idx=0;
    while(idx<NewCardSz) {
        if (CardSet::Size() > 0) NewCards[idx++] = CardSet::Deal();
        if (Set.Size() > 0) NewCards[idx++] = Set.Deal();
    }

    nCards = NewCardSz;
    int *TmpCardPtr;
    TmpCardPtr = Card;
    Card = NULL;
    delete [] TmpCardPtr;
    Card = NewCards;
}

/*************** ACCESSORS ***************/
/* This accessor function should return the value of nCards. */
int CardSet::Size() const
{
    return nCards;
}

bool CardSet::IsEmpty() const
{
    return (Card == NULL);
}

// This accessor function, uses PrintCard to print the contents of the set,
// five cards to a line.
void CardSet::Print() const
{
    if (debug) {
        cout<<"\n[DEBUG]";
        for (int j=0; j < nCards; j++) {
            if ((j%10) == 0) cout<<endl;
            cout<<Card[j]<<" ";
        }
        cout<<endl;
    }

    for (int i=0; i < nCards; i++) {
        if ((i%5) == 0) cout<<endl;
        PrintCard(Card[i]);
    }
    cout<<endl<<endl;
}

// Private function to print out usual representation of playing card.
// Input is integer from 0 to 51.  There is no error checking.
void CardSet::PrintCard(int c) const
{
	int Rank = c%13;
	int Suit = c/13;
	const char NameSuit[5] = "SCDH";
	const char NameRank[14] = "23456789XJQKA";
	cout<<NameRank[Rank]<<NameSuit[Suit]<<" ";
}
