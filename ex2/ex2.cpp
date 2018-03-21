/********************************************************************
 * CSCI251 - Ex2
 * <Dinh Che - dbac496>
 ********************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "ec_malloc.h"
using namespace std;

// ============= User Defined types ==================================

// linked list record
struct PhoneRecord
{
	long PhoneNo;
	char *Name;
	char *Address;
	PhoneRecord *Next; // pointer to next record in list
};


// ============= Global Data =========================================

const char cDataFilename[] = "phone.txt";
PhoneRecord *Head; // head of linked list
const unsigned int cNameSz = 20;
const unsigned int cAddrSz = 40;

// ============= Function Prototypes =========================

void Initialise();
void ReadFile();
void AddRecord(long phoneNo,char *name,char *address);
void FindRecord();
void RemoveRecord();
void DisplayAllRecs();
void DisplayRec(PhoneRecord *Rec);
void DeleteList();
void *ec_malloc(unsigned int);

// ============= Main Function ================================

int main()
{
    cout<<"Begin test"<<endl<<endl;
    Initialise();
	ReadFile();
    DisplayAllRecs();
	FindRecord();
	RemoveRecord();
	FindRecord();
	DeleteList();
	cout<<endl<<"End test"<<endl;
	return 0;
}

// ============= Function Definitions =========================

//Initialises linked list
void Initialise()
{
	Head = NULL;
}

// Reads data file into linked list
void ReadFile()
{
	ifstream fin(cDataFilename);
    int recCount=0;
	long phoneNo;

    char *name, *address;
    name = (char *)ec_malloc(cNameSz);
    address = (char *)ec_malloc(cAddrSz);

	if (!fin.good()) {
		cout<<"[DEBUG]: Unable to read file"<<endl;
		exit(1);
	}

    while(!fin.eof()) {
        fin >> phoneNo;
        if (fin.fail()) break;
        fin.clear();
        fin.ignore(256, '\n');
        // fin.getline(name, cNameSz, '\n');

        // Dynamic Char Memory
        int i=0;
        char c;
        char *str;
        str = (char *)ec_malloc(sizeof(char));

        while((c = fin.get()) != '\n') {
            // cout<<strlen(str)<<endl;
            realloc(str, (sizeof(str) + sizeof(char)));
            str[i++] = c;
            // cout<<str<<endl;
        }

        str[i] = '\0';
        name = str;

        fin.getline(address, cAddrSz, '\n');

        AddRecord(phoneNo, name, address);

        // free(str);
        recCount++;
	}
    fin.close();
    cout<<recCount<<" records were read."<<endl;
    free(name);
    free(address);
}

// Adds record to tail of linked list
void AddRecord(long phoneNo, char *name, char *address)
{
    PhoneRecord *tmpPhoneRecPtr;
    tmpPhoneRecPtr = new PhoneRecord;

    tmpPhoneRecPtr->PhoneNo = phoneNo;
    // Dynamic Memory Alloc for name and address arrays
    tmpPhoneRecPtr->Name = new char[strlen(name)+1];  // Additional char bit for \0
    tmpPhoneRecPtr->Address = new char[strlen(address)+1];
    strcpy(tmpPhoneRecPtr->Name, name);
    strcpy(tmpPhoneRecPtr->Address, address);
    // cout<<strlen(tmpName)+1<<endl;
    // cout<<strlen(tmpAddress)+1<<endl;


    tmpPhoneRecPtr->Next = NULL;
    if (Head == NULL)
        Head = tmpPhoneRecPtr;
    else {
        PhoneRecord *tmpCurrentPtr;
        tmpCurrentPtr = Head;
        while (tmpCurrentPtr->Next != NULL)
            tmpCurrentPtr = tmpCurrentPtr->Next;
        tmpCurrentPtr->Next = tmpPhoneRecPtr;
    }
}

// Finds record in linked list and displays it
void FindRecord()
{
    long phoneNo;
    char ans;
    cout<<"\nEnter phone number to find: ";
    cin>>phoneNo;
    PhoneRecord *tmpCurrent;
    tmpCurrent = Head;
    while (tmpCurrent != NULL && tmpCurrent->PhoneNo != phoneNo)
        tmpCurrent = tmpCurrent->Next;
    if (tmpCurrent != NULL) DisplayRec(tmpCurrent);
    else cout<<"Record not found!"<<endl;
    /*while (tmpCurrent != NULL) {
        cout<<"\nDisplay next record [y/N]: ";
        cin>>ans;
        if(ans=='n' || ans=='\n' || ans==' ') break;
        tmpCurrent=tmpCurrent->Next;
        if(ans='y') DisplayRec(tmpCurrent);
    }*/
}

// Removes record from head of linked list
void RemoveRecord()
{
    if (Head == NULL) cout << "[DEBUG] List is empty";
    else {
        cout <<"\nHead record removed."<< endl;
        DisplayRec(Head);
        PhoneRecord *tmpPhoneRecPtr;
        tmpPhoneRecPtr = Head;
        Head = Head->Next;
        delete tmpPhoneRecPtr;
    }
}

// Prints all records on screen one at a time
void DisplayAllRecs()
{
	char Ans;
	PhoneRecord *tmpCurrentPtr;
	tmpCurrentPtr = Head;
	while (tmpCurrentPtr != NULL) {
		DisplayRec(tmpCurrentPtr);
		cout<<"\nDisplay next record: ";
		cin>>Ans;
		if(Ans=='n') break;
		tmpCurrentPtr = tmpCurrentPtr->Next;
	}
	cout << endl;
}

// Displays record on screen
void DisplayRec(PhoneRecord *RecPtr)
{
	cout<<'\n'<<RecPtr->Name<<endl;
	cout<<RecPtr->Address<<endl;
	cout<<RecPtr->PhoneNo<<endl<<endl;
}

// Deletes memory in list
void DeleteList()
{
    PhoneRecord *tmpCurrentPtr;
    tmpCurrentPtr = Head;
    while (Head != NULL) {
        PhoneRecord *tmpPhoneRecPtr;
        tmpPhoneRecPtr = Head;
        Head = Head->Next;
        delete tmpPhoneRecPtr;
    }
    cout<<"List deleted."<< endl;
}
