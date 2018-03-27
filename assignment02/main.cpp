/*******************************************************
 * main.cpp - Contains driver program for class CardSet.
 * Move the comments as you complete the implementation.
 *     DO NOT ALTER THE CODE IN THIS FILE
 *******************************************************/

#include <iostream>
#include "CardSet.h"
using namespace std;


int main()
{
	CardSet CardSet1(104), CardSet2(12), CardSet3, CardSet4, CardSet5, CardSet6;

	// cout<<"[TEST] 1%: "<<1%13<<endl;
	// cout<<"[TEST] 1/: "<<1/13<<endl;
	// cout<<"[TEST] 2%: "<<2%13<<endl;
	// cout<<"[TEST] 2/: "<<2/13<<endl;
	// cout<<"[TEST] 12%: "<<12%13<<endl;
	// cout<<"[TEST] 12/: "<<12/13<<endl;
	// cout<<"[TEST] 13%: "<<13%13<<endl;
	// cout<<"[TEST] 13/: "<<13/13<<endl;
	// cout<<"[TEST] 14%: "<<114%13<<endl;
	// cout<<"[TEST] 14/: "<<14/13<<endl;
	// cout<<"[TEST] 52%: "<<52%13<<endl;
	// cout<<"[TEST] 52/: "<<52/13<<endl;
	// cout<<"[TEST] 53%: "<<53%13<<endl;
	// cout<<"[TEST] 53/: "<<53/13<<endl;

	cout << "BEGINNING OF CARDSET TESTS . . .  "<< endl << endl;

	cout << "Test 1: Constructors:" << endl;
	cout << "CardSet1 Size: " << CardSet1.Size() << endl;
	cout << "CardSet3 Size: " << CardSet3.Size() << endl;
	cout << "Printout of CardSet1:" << endl;
	CardSet1.Print();
	cout << "Printout of CardSet2:" << endl;
	CardSet2.Print();
	cout << endl;
/*
	cout << "Test 2: Adding and removing cards to CardSet1: "<< endl;
	int Card = CardSet1.Deal();
	cout << "Dealing 1 card: "<< Card << endl;
	cout << "CardSet1 Size: " << CardSet1.Size() << endl;
	cout << "Adding card "<< Card << endl;
	CardSet1.AddCard(Card);
	cout << "CardSet1 Size: " << CardSet1.Size() << endl;
	cout << "Printout of CardSet1:" << endl;
	CardSet1.Print();
	cout << endl;

	cout << "Test 3: Normal Shuffle: "<< endl;
	CardSet1.Shuffle();
	cout << "Printout of shuffled CardSet1:" << endl;
	CardSet1.Print();
	cout << endl;

	cout << "Test 4: Merge Shuffle: "<< endl;
	cout << "Printout of CardSet2:" << endl;
	CardSet2.Print();
	CardSet1.MergeShuffle(CardSet2);
	cout << "Printout of CardSet1 Merged with CardSet2:" << endl;
	CardSet1.Print();
	cout << endl;

	cout << "Test 5: Dealing 3 Cards from CardSet1 into CardSet3 and CardSet4: " << endl;
	CardSet1.Deal(3,CardSet3,CardSet4);
	cout << "Printout of CardSet1:" << endl;
	CardSet1.Print();
	cout << "Printout of CardSet3:" << endl;
	CardSet3.Print();
	cout << "Printout of CardSet4:" << endl;
	CardSet4.Print();
	cout << endl;

	cout << "Test 6: Dealing 3 Cards from CardSet1 into CardSet 3, 4, 5 & 6: " << endl;
	CardSet1.Deal(3,CardSet3,CardSet4,CardSet5,CardSet6);
	cout << "Printout of CardSet1:" << endl;
	CardSet1.Print();
	cout << "Printout of CardSet3:" << endl;
	CardSet3.Print();
	cout << "Printout of CardSet4:" << endl;
	CardSet4.Print();
	cout << "Printout of CardSet5:" << endl;
	CardSet5.Print();
	cout << "Printout of CardSet6:" << endl;
	CardSet6.Print();
	cout << endl;
*/
	cout << ". . . END OF TESTS"<< endl;
	return 0;
}
