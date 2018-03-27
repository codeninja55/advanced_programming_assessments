/**********************************************
* CardSet.cpp - Contains implementation of class CardSet
* <name, studNo, login, date completed, etc>
***********************************************/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "CardSet.h"
using namespace std;

/*************** CONSTRUCTORS ***************/

// Default constructor sets up 0 cards
CardSet::CardSet()
{
    nCards = 0;
    Card = NULL;
}

// Initialising constructor
/*
 * It should set up a set of cards, where the number of cards is the argument passed.
 * The array Card should be filled with cards starting from 0, up to the number of cards
 * needed, but never exceeding the number 51. For example if a set of 104 cards is requested,
 * the array would contain 0 to 51 twice.
 */
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
    if (!Card == NULL) {
        Tmp = Card;
        Card = NULL;
        delete [] Tmp;
    }
}

/*************** MUTATORS ***************/

/* This function should return the value of the first card in the set,
 * located in the 0th element of the array. The function should then create fresh memory,
 * transfer the rest of the set to this new memory, and then delete the old memory.
 * That is, this class never has any vacant space in it. The array is always the same
 * size as the number of actual cards it holds. If the set is empty, this function
 * should print an error message and terminate the program.
*/
int CardSet::Deal()
{
    if (Card == NULL) return -1;
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
    // Dynamic realloc of array
    int *NewCards = new int[++nCards];
    NewCards[0] = i;
    for (int j=0; j < nCards; j++) NewCards[++i] = Card[j];
    delete [] Card;
    Card = NewCards;
}

/* This function takes the current set and the set provided as an argument and makes the
 * current set contain all the cards from the two sets, with cards alternating from each
 * set as far as possible. After this function the argument set will be empty. */
void MergeShuffle(CardSet& Set)
{

}

/*************** ACCESSORS ***************/
// This accessor function should return the value of nCards.
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
    cout<<"[DEBUG]"<<endl;
    for (int j=0; j < nCards; j++) cout<<Card[j]<<" ";
    cout<<endl;

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
