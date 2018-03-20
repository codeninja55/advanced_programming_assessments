/********************************************************************
 * CSCI251 - Ex2
 * <Dinh Che - dbac496>
 ********************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
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

const char cDataFileName[] = "phone.txt";
PhoneRecord *Head; // head of linked list
const unsigned int cNameSz = 20;
const unsigned int cAddressSz = 40;


// ============= Function Prototypes =========================

void Initialise();
void ReadFile();
void AddRecord(long PhoneNo,char *Name,char *Address);
void FindRecord();
void RemoveRecord();
void DisplayAllRecs();
void DisplayRec(PhoneRecord *Rec);
void DeleteList();


// ============= Main Function ================================

int main()
{
	cout << "Begin test" << endl << endl;
	Initialise();
	ReadFile();
    DisplayAllRecs();
	FindRecord();
	RemoveRecord();
	FindRecord();
	DeleteList();
	cout << endl << "End test" << endl;
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
	ifstream fin(cDataFileName);
    int recCount = 0;
    long phoneNo;
    char *name, *address;
    name = new char[cNameSz];
    address = new char[cAddressSz];

	if (!fin.good()) {
		cout << "[DEBUG]: Unable to read file" << endl;
		exit(1);
	}

    while(!fin.eof()) {
        fin >> phoneNo;
        if (fin.fail()) break;
        fin.clear();
        fin.ignore(256,'\n');
        fin.getline(name, cNameSz, '\n');
        fin.getline(address, cAddressSz, '\n');
        AddRecord(phoneNo, name, address);
        recCount++;
    }
    fin.close();
    cout<<recCount<<" records were read."<<endl;
}

// Adds record to tail of linked list
void AddRecord(long PhoneNo, char *Name, char *Address)
{
    PhoneRecord *tmpPhoneRecPtr;
    tmpPhoneRecPtr = new PhoneRecord;

    // Dynamic Memory Alloc for Name and Address arrays
    char *tmpName, *tmpAddress;
//    tmpName = Name;
//    tmpAddress = Address;
    tmpName = new char[cNameSz];
    tmpAddress = new char[cAddressSz];

    strcpy(tmpName, Name);
    strcpy(tmpAddress, Address);

    tmpPhoneRecPtr->PhoneNo = PhoneNo;
    tmpPhoneRecPtr->Name = tmpName;
    tmpPhoneRecPtr->Address = tmpAddress;

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

//    delete tmpName;
//    delete tmpAddress;
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
        cout << "\nHead record removed." << endl;
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
	PhoneRecord *Crnt;
	Crnt = Head;
	while(Crnt!=NULL) {
		DisplayRec(Crnt);
		cout<<"\nDisplay next record: ";
		cin>>Ans;
		if(Ans=='n') break;
		Crnt=Crnt->Next;
	}
	cout << endl;
}

// Displays record on screen
void DisplayRec(PhoneRecord *RecPtr)
{
	cout<<'\n'<<RecPtr->Name<<endl;
	cout<<RecPtr->Address<<endl;
	cout<<RecPtr->PhoneNo<<endl;
	cout<<endl;
}

// Deletes memory in list
void DeleteList()
{
    PhoneRecord *tmpCurrent;
    tmpCurrent = Head;
    while (Head != NULL) {
        PhoneRecord *tmpPhoneRecPtr;
        tmpPhoneRecPtr = Head;
        Head = Head->Next;
        delete tmpPhoneRecPtr;
    }
    cout << "List deleted." << endl;
}

