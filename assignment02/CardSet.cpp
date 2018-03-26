/**********************************************
* CardSet.cpp - Contains implementation of class CardSet
* <name, studNo, login, date completed, etc>
***********************************************/

#include <iostream>
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
CardSet::CardSet(int i)
{
    nCards = i;

    if (nCards > 51) {}
    //if (nCards <= 51) Card = Card[nCards];
    //else if ((nCards % 51) != 0) Card = Card[nCards];
    //else Card = Card[nCards % 51];

}

/*************** DESTRUCTOR ***************/

CardSet::~CardSet()
{

}

/*************** MUTATORS ***************/


/*************** ACCESSORS ***************/
// This accessor function should return the value of nCards.
int CardSet::Size() const
{
    return nCards;
}

// This accessor function, uses PrintCard to print the contents of the set, five cards to a line.
void CardSet::Print() const
{
    for (int i=0; i < nCards; i++) {
        if ((i%5)==0) cout<<endl;
        PrintCard(i);
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
