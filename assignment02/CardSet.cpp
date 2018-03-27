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

    if (n <= 52)
        for (int i=0; i<n; i++) Card[i] = i;
    else {
        int idx = 0;
        // For loop for 1st set of 52
        for (int j=0; j < floor(n/52); j++) {
            for (int k=0; k<52; k++) Card[idx++] = k;
        }

        // For loop for rest of cards with modulo
        for (int l=0; l < n%52; l++) Card[idx++] = l;
    }
}

/*************** DESTRUCTOR ***************/

CardSet::~CardSet()
{
    if (!(Card == NULL)); delete [] Card;
}

/*************** MUTATORS ***************/

// Function to add a card to the current hand.
void CardSet::AddCard(int i)
{
    // Dynamic realloc of array
}

/*************** ACCESSORS ***************/
// This accessor function should return the value of nCards.
int CardSet::Size() const
{
    return nCards;
}

// This accessor function, uses PrintCard to print the contents of the set, five cards to a line.
void CardSet::Print() const
{
    // cout<<"[DEBUG]"<<endl;
    // for (int j=0; j < nCards; j++) cout<<Card[j]<<" ";
    // cout<<endl;

    for (int i=0; i < nCards; i++) {
        if ((i%5) == 0) cout<<endl;
        if (i>=52) PrintCard(i%52);
        else PrintCard(i);
    }
    cout<<endl<<endl;
}

// Private function to print out usual representation of playing card.
// Input is integer from 0 to 51.  There is no error checking.
void CardSet::PrintCard(int c) const
{
	int Rank = c%13;
	int Suit = c/13;  // For the 2nd deck, this is out of arr range
	const char NameSuit[5] = "SCDH";
	const char NameRank[14] = "23456789XJQKA";
	cout<<NameRank[Rank]<<NameSuit[Suit]<<" ";
}
