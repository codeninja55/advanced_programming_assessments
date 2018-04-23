/*********************************************************************
 * CSCI251/851 - Exercise 3
 * list.h - Declaration of LinkedList class
 * Put you name, login and the date last modified here.
 *
 *********************************************************************/

#ifndef LIST_H
#define LIST_H


struct Node;

typedef Node *NodePtr;
typedef int IntPtr;

struct Node
{
	int Item;
	NodePtr Next;
};

class LinkedList
{
	public:
		LinkedList();                   // default constructor
		LinkedList(const LinkedList&);	// copy constructor
        ~LinkedList();                  // destructor
        LinkedList& operator=(const LinkedList&); // Overloaded assignment operator
		void AddHead(int);              // adds item to head
		int  RemoveHead();              // removes item from head
		bool IsEmpty();                 // returns true if list is empty
		void Print();                   // prints list

	private:
		NodePtr Head;
};

#endif

