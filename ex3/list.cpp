/*********************************************************************
 * CSCI251/851 - Exercise 3
 * list.cpp - Implementation of LinkedList class.
 * Dinh Che - 5721970 - dbac496 - 2018-04-24
 *
 *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include "list.h"
using namespace std;

// Default constructor
LinkedList::LinkedList() : Head(NULL) { }

// Copy constructor
LinkedList::LinkedList(const LinkedList& otherList)
{
    Head = NULL;
    *this = otherList;
    /*LinkedList tmpList;
    Head = NULL;
    NodePtr curr = otherList.Head;
    while (curr != NULL) {
        tmpList.AddHead(curr->Item);
        curr = curr->Next;
    }

    while (!tmpList.IsEmpty())
        LinkedList::AddHead(tmpList.RemoveHead());*/
}

// Destructor
LinkedList::~LinkedList()
{
    while (Head != NULL) {
        NodePtr temp = Head;
        Head = Head->Next;
        delete temp;
    }
}

// Assignment operator overload
LinkedList& LinkedList::operator=(const LinkedList& rOperand)
{
    this->~LinkedList();
    LinkedList tmpList;

    if (Head == rOperand.Head) exit(0);

    NodePtr curr = rOperand.Head;
    while (curr != NULL) {
        tmpList.AddHead(curr->Item);
        curr = curr->Next;
    }

    while (!tmpList.IsEmpty())
        LinkedList::AddHead(tmpList.RemoveHead());

    return *this;
}

// Adds item to head of list
void LinkedList::AddHead(int Item)
{ 
    NodePtr tmp = new Node;
    tmp->Item = Item;
    tmp->Next = Head;
    Head = tmp;
}

// Removes head node and returns item
int LinkedList::RemoveHead()
{
    if (LinkedList::IsEmpty()) {
        cout<<"List is empty"<<endl;
        exit(1);
    }

    int tmpItem = Head->Item;
    NodePtr tmp = Head;
    Head = Head->Next;
    delete tmp;
    return tmpItem;
}

// Returns true if list is empty
bool LinkedList::IsEmpty() { return (Head == NULL); }

// Prints contents of linked list
void LinkedList::Print() {
    if (LinkedList::IsEmpty()) {
        cout<<"List is empty"<<endl;
        return;
    }
    NodePtr curr = Head;
    while (curr != NULL) {
        cout<<curr->Item<<" ";
        curr = curr->Next;
    }
    cout<<endl;
}
