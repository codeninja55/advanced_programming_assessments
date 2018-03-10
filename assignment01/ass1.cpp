/********************************************************************
 * CSCI251 - Ass1
 * <Dinh Che - dbac496>
 * ass1.cpp - Contains function definitions for student records database
 ********************************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;

// ============== Constants ==========================================

const char cTextFileName[]   = "ass1.txt";
const char cBinaryFileName[] = "ass1.dat";
const int cMaxRecs = 100;
const int cMaxChars = 30;
const int cMaxSubjects = 8;

// ============= User Defined types ==================================
enum StatusType { eEnrolled, eProvisional, eWithdrawn };

struct SubjectType {
    char Code[8];
    StatusType Status;
    int Mark;
};

struct StudentRecord {
	long StudentNo;
	char FirstName[cMaxChars];
	char LastName[cMaxChars];
	int NumSubjects;
	SubjectType Subjects[cMaxSubjects];
};

// ============= Global Data =========================================
StudentRecord gRecs[cMaxRecs];
int gNumRecs = 0;


// ============= Private Function Prototypes =========================
void PrintRecord(int i);
int FindRecord(long StudentNum);

// ============= Public Function Definitions =========================

void ReadFile() { // Reads data file into array
    ifstream fin;
    fin.open(cTextFileName);
    int statusInt, i = 0;

    if(!fin.good()) {
        cout << "[DEBUG] Cant find text data file!\n" << endl;
        exit(1);
    }

    fin >> gRecs[i].StudentNo;

    while(!fin.eof() && i < cMaxRecs) {
        fin >> gRecs[i].FirstName;
        fin >> gRecs[i].LastName;
        fin >> gRecs[i].NumSubjects;

        for (int j = 0; j < gRecs[i].NumSubjects; j++) {
            fin >> gRecs[i].Subjects[j].Code;
            fin >> statusInt;
            gRecs[i].Subjects[j].Status = StatusType(statusInt);
            fin >> gRecs[i].Subjects[j].Mark;
        }

        i++;
        fin >> gRecs[i].StudentNo;
    }

    gNumRecs = i;
    fin.close();
    cout << gNumRecs << " records read.\n" << endl;
}

void DisplayRecord() { // Displays specified record on screen
    int studentNoInput;

    cout << "Enter student number: ";
    cin >> studentNoInput;
    int found = FindRecord(studentNoInput);

    if (found < 0) cout << "/nRecord not found" << endl;
    else PrintRecord(found);
}

void SaveFile() { // Writes array to text data file
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

void UpdateRecord() { // updates status or mark of specified subject of specified student number
    long int studentNoInput;
    char subjectCodeInput[8], editOption[1];
    cout << "Enter student number: ";
    cin >> studentNoInput;

    int found = FindRecord(studentNoInput);

    if (!found)
        cout << "Record not found!\n" << endl;
    else {
        PrintRecord(found);
        cout << "\nEnter subject code i.e. CSCI251: ";
        cin >> subjectCodeInput;

        int subjectFlag = 0;
        for (int j = 0; j < gRecs[found].NumSubjects; j++) {
            if (strcmp(gRecs[found].Subjects[j].Code, subjectCodeInput) == 0) {
                cout << "Select status or mark (s/m): ";
                cin >> editOption;

                if (strncmp(editOption, "s", 1) == 0) {
                    char statusInput[1];
                    cout << "Select new status\n"
                         << "e: enrolled\n"
                         << "p: provisional\n"
                         << "w: withdrawn\n"
                         << "Enter new status: ";
                    cin >> statusInput;

                    if (strncmp(statusInput, "e", 1) == 0) {
                        gRecs[found].Subjects[j].Status = StatusType(0);
                        cout << "New status: enrolled" << endl;
                    } else if (strncmp(statusInput, "p", 1) == 0) {
                        gRecs[found].Subjects[j].Status = StatusType(1);
                        cout << "New status: provisional" << endl;
                    } else if (strncmp(statusInput, "w", 1) == 0) {
                        gRecs[found].Subjects[j].Status = StatusType(2);
                        cout << "New status: withdrawn" << endl;
                    } else
                        cout << "\nIncorrect choice!\n";
                } else if (strncmp(editOption, "m", 1) == 0) {
                    int newMark;
                    cout << "Enter new mark: ";
                    cin >> gRecs[found].Subjects[j].Mark;
                    cout << gRecs[found].Subjects[j].Code << " Mark (new): " << gRecs[found].Subjects[j].Mark;
                } else {
                    cout << "\nIncorrect choice!\n\n";
                }
            } else
                subjectFlag++;
        }

        if (subjectFlag == (gRecs[found].NumSubjects - 1)) cout << "\nSubject code not found!\n";
    }
}


// ============= Private Function Definitions =========================

void PrintRecord(int i) { // Prints record i on screen
    cout << "\nStudent No. " << gRecs[i].StudentNo << endl
         << "First Name: " << gRecs[i].FirstName << endl
         << "Last Name: " << gRecs[i].LastName << endl
         << "Subjects (" << gRecs[i].NumSubjects << "):" << endl;

    for (int j = 0; j < gRecs[i].NumSubjects; j++) {
        cout << "  " << gRecs[i].Subjects[j].Code << " ";

        switch (gRecs[i].Subjects[j].Status) {
            case eEnrolled:
                cout << "Enrolled";
                break;
            case eProvisional:
                cout << "Provisional";
                break;
            case eWithdrawn:
                cout << "Withdrawn";
                break;
        }
        cout << " " << gRecs[i].Subjects[j].Mark << endl;
    }
}

int FindRecord(long StudentNo) { // returns index of matching record or -1 if not found
    for (int i = 0; i < gNumRecs; i++)
        if (gRecs[i].StudentNo == StudentNo) return i;
	return -1;
}
