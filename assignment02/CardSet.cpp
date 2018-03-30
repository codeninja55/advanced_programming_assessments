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
    if (Card != NULL) {
        int *Tmp;
        Tmp = Card;
        Card = NULL;
        delete [] Tmp;
    }
}

/*************** COPY CONSTRUCTOR & ASSIGNMENT OVERLOAD***************/
/*CardSet::CardSet(const CardSet& other)
{
    if (!other.IsEmpty()) {
        nCards = other.Size();
        for (int i=0; i < nCards; i++) Card[i] = other.Deal();
    }
}

CardSet& CardSet::operator=(const CardSet& other) const
{
    if (this != other) {
        delete [] Card;
        nCards = other.Size();
        //int *localCardSet = new int[nCards];
        for (int i=0; i < nCards; i++) Card[i] = other.Deal();
        //for (int i=0; i < nCards; i++) localCardSet[i] = other.Deal();
    }
    return *this;
}*/

/*************** MUTATORS ***************/

/* Returns the first card in the set and reallocates memory for a new set with 1 less card. */
int CardSet::Deal()
{
    if (Card == NULL) {
        cout<<"[ERROR] The Card set is empty."<<endl;
        exit(1);
    }

    int DealCard = Card[0];
    nCards -= 1;
    int *newCardSet = new int[nCards];
    int j=0;
    for (int i=1; i <= nCards; i++) newCardSet[j++] = Card[i];

    int *Tmp;
    Tmp = Card;
    delete [] Tmp;
    Card = newCardSet;
    return DealCard;
}

/* This function deals two hands into the two CardSet arguments passed.
 * The cards should be removed from the current set one at a time, placing
 * the cards into alternate hands. */
void CardSet::Deal(int n, CardSet& Set1, CardSet& Set2)
{
    // If there aren't enough cards in the current set for the deal,
    // print an error message and terminate.
    if (CardSet::Size() < n*2) {
        cout<<"[ERROR] There is not enough cards in the current set to deal "
            <<n<<" cards."<<endl;
        exit(1);
    }

    // Cards removed from current set one at a time, placed into alternate hands
    for (int i=0; i < n; i++) {
        Set1.AddCard(CardSet::Deal());
        Set2.AddCard(CardSet::Deal());
    }
}

void CardSet::Deal(int n, CardSet& Set1, CardSet& Set2, CardSet& Set3, CardSet& Set4)
{
    if (CardSet::Size() < n*4) {
        cout<<"[ERROR] There is not enough cards in the current set to deal "
            <<n<<" cards."<<endl;
        exit(1);
    }

    for (int i=0; i < n; i++) {
        Set1.AddCard(Deal());
        Set2.AddCard(Deal());
        Set3.AddCard(Deal());
        Set4.AddCard(Deal());
    }
}

/* Function to add a card to the current hand. */
void CardSet::AddCard(int newCard)
{
    nCards += 1;
    // Dynamic realloc of array
    int *newCardSet = new int[nCards];
    newCardSet[0] = newCard;

    int i=1;
    if (CardSet::Size() > 1)
        for (int j=0; j < nCards; j++) newCardSet[i++] = Card[j];

    int *Tmp;
    Tmp = Card;
    delete [] Tmp;
    Card = newCardSet;
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
// TODO: Need to debug. There is an error with memory alloc
void CardSet::MergeShuffle(CardSet& Set)
{
    int newCardSz = nCards + Set.Size();  // Maintain a separate counter
    int *newCardSet = new int[newCardSz];  // Alloc memory for superset of Cards

    int idx=0;
    while(idx<newCardSz) {
        if (CardSet::Size() > 0) newCardSet[idx++] = CardSet::Deal();
        if (Set.Size() > 0) newCardSet[idx++] = Set.Deal();
    }

    nCards = newCardSz;
    int *Tmp;
    Tmp = Card;
    delete [] Tmp;
    Card = newCardSet;
}

/*************** ACCESSORS ***************/
/* This accessor function should return the value of nCards. */
int CardSet::Size() const
{
    return nCards;
}

/* This function returns a bool if the CardSet is empty */
bool CardSet::IsEmpty() const
{
    return (Card == NULL);
}

/* This function, uses PrintCard to print the contents of the set, five cards to a line. */
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

/* Private function to print out usual representation of playing card.
 * Input is integer from 0 to 51.  There is no error checking. */
void CardSet::PrintCard(int c) const
{
	int Rank = c%13;
	int Suit = c/13;
	const char NameSuit[5] = "SCDH";
	const char NameRank[14] = "23456789XJQKA";
	cout<<NameRank[Rank]<<NameSuit[Suit]<<" ";
}
