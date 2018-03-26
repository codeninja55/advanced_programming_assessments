/**********************************************
* CardSet.cpp - Contains implementation of class CardSet
* <name, studNo, login, date completed, etc>
***********************************************/

#include <iostream>
#include "CardSet.h"
using namespace std;



// Private function to print out usual representation of playing card.
// Input is integer from 0 to 51.  There is no error checking.

void CardSet::PrintCard(int c) const
{
	int Rank = c%13;
	int Suit = c/13;
	const char NameSuit[5] = "SCDH";
	const char NameRank[14] = "23456789XJQKA";
	cout << NameRank[Rank] << NameSuit[Suit];
}
