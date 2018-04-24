/*********************************************************************
 * CSCI251/851 - Exercise 3
 * main.cpp - main() driver for testing LinkedList class.
 * Put you name, login and the date last modified here.
 *
 *********************************************************************/

#include <iostream>
#include "list.h"
using namespace std;


int main()
{
	cout << "===== Testing Step-1 =====\n";
	cout << "Testing default construstor...\n";
	LinkedList L1;
	L1.Print(); // should be empty
	cout<<"\nTesting AddHead()...\n";
	for(int i=0; i<10; i++){
		cout << i << ' ';
		L1.AddHead(i);
	}
	cout << endl;
	L1.Print();
	cout << "\nTesting IsEmpty() and RemoveHead()..."<<endl;
	while(!L1.IsEmpty())
		cout << L1.RemoveHead()<< ' '; // should be printed in reverse
	cout << endl;
	L1.Print(); // should be empty

	cout<<"\n\n===== Testing Step-2 =====\n";
	for(int i=0; i<10; i++)
		L1.AddHead(i);
	cout << "\nTesting copy constructor...\n";
	LinkedList L2(L1);
	L1.Print();
	L2.Print();
	cout << endl;


	cout << "\n\n===== Testing Step-3 =====\n";
	cout << "Testing assignment operator...\n";
	LinkedList L3;
	for(int i=10; i<20; i++){
		cout << i << ' ';
		L3.AddHead(i);
	}
	cout << endl;
	L1 = L2 = L3;
	L1.Print();
	L2.Print();
	L3.Print();
	cout << endl;
	cout << "\n===== End of Tests =====\n";

	return 0;
}

