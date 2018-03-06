/********************************************************************
 * CSCI251 - Ass1
 * <Name - Login>
 * ass1.cpp - Contains function definitions for student records database
 ********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

// ============== Constants ==========================================

const char cTextFileName[]   = "ass1.txt";
const char cBinaryFileName[] = "ass1.dat";
const int cMaxRecs = 100;
const int cMaxChars = 30;
const int cMaxSubjects = 8;

// ============= User Defined types ==================================

enum StatusType{eEnrolled,eProvisional,eWithdrawn};
struct SubjectType{ char Code[8]; StatusType Status; int Mark;};

struct StudentRecord{
	long StudentNo;
	char FirstName[cMaxChars];
	char LastName[cMaxChars];
	int NumSubjects;
	SubjectType Subjects[cMaxSubjects];
};


// ============= Global Data =========================================

StudentRecord gRecs[cMaxRecs];
int gNumRecs=0;


// ============= Private Function Prototypes =========================

void PrintRecord(int i);
int FindRecord(long StudentNum);

// ============= Public Function Definitions =========================


void ReadFile()
{// Reads data file into array
/*
	open TextFileName
	if open no good
		print "Cant find text data file!\n";
		exit;
	i = 0
	read gRecs[i] StudentNo;
	while not eof
		read gRecs[i] FirstName;
		read gRecs[i] LastName;
		read gRecs[i] NumSubjects;
		for j=0 to NumSubjects  
			read gRecs[i] Subjects[j] Code;
			read gRecs[i] Subjects[j] Status;
			read gRecs[i] Subjects[j] Mark;
		inc i
		read gRecs[i] StudentNo;

	gNumRecs = i
	close textfile
	print gNumRecs " records read"
*/
}

void DisplayRecord()
{// Displays specified record on screen
/*
	print "Enter student number: "
	read student number
	i = FindRecord(StudentNumber);
	if record not found
		print "Record not found"
	else
		PrintRecord(i)
*/
}

void SaveFile()
{// Writes array to text data file
/*
	open TextFileName
	if open no good
		print "Problem opening data file!\n";
		exit(1);
	for i=0 to gNumRecs
		write gRecs[i] StudentNo;
		write gRecs[i] FirstName;
		write gRecs[i] LastName;
		write gRecs[i] NumSubjects;
		for j=0 to NumSubjects  
			write gRecs[i] Subjects[j] Code;
			write gRecs[i] Subjects[j] Status;
			write gRecs[i] Subjects[j] Mark;
	close textfile
	print gNumRecs " records saved"
*/
}

void UpdateRecord()
{// updates status or mark of specified subject of specified student number
/*
	print "Enter student number: "
	read student number
	i = FindRecord(StudentNumber);
	if record not found 
		print "Record not found!"
	else
		display the found record
		request subject code from user
		if subject code is found then
			ask user to select status or mark
			request new status or mark
			update status or mark
		else
			print "Subject code not found!"
*/
}


// ============= Private Function Definitions =========================

void PrintRecord(int i)
{ // Prints record i on screen

/*
	print gRecs[i] StudentNo;
	print gRecs[i] FirstName;
	print gRecs[i] LastName;
	print gRecs[i] NumSubjects;
	for j=0 to NumSubjects  
		print gRecs[i] Subjects[j] Code;
		print gRecs[i] Subjects[j] Status;
		print gRecs[i] Subjects[j] Mark;
*/
}

int FindRecord(long StudentNo)
{// returns index of matching record or -1 if not found
/*
	for i=0 to gRecs
		if gStudRecs[i] StudentNo == StudentNo
			return i
*/
	return -1

}
