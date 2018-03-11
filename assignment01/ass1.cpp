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
#include <sstream>
using namespace std;

// ============== Note ==========================================
//#include <typeinfo>
//#include "type.h"

/* Use these directives along with shell addition -std=c++11 to activate type checking.
 * Type checking usage: cout << type(variable_type); */

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
bool ReadTextFile(const char Filename[]);
bool WriteTextFile(const char Filename[]);
bool ReadBinaryFile(const char Filename[]);
bool WriteBinaryFile(const char Filename[]);
void WriteBinaryRecord(const char Filename[], int Pos);

// TODO Ask Koren why you cannot use a const char[] when you have a param for char[]

// ============= Public Function Definitions =========================

void ReadFile() { // Reads data file into array
    if(!ReadBinaryFile(cBinaryFileName)) {
        if (ReadTextFile(cTextFileName)) WriteBinaryFile(cBinaryFileName);
        else cout << "[DEBUG] Unable to read both binary and text file." << endl;
    }
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
    ofstream fout;
    fout.open(cTextFileName);

    if (!fout.good()) {
        cout << "[DEBUG] Problem opening data file!\n";
        exit(1);
    }

    for (int i = 0; i < gNumRecs; i++) {
        fout << gRecs[i].StudentNo << endl;
        fout << gRecs[i].FirstName << " ";
        fout << gRecs[i].LastName << endl;
        fout << gRecs[i].NumSubjects << endl;
        for (int j = 0; j < gRecs[i].NumSubjects; j++) {
            fout << gRecs[i].Subjects[j].Code << " ";
            fout << gRecs[i].Subjects[j].Status << " ";
            fout << gRecs[i].Subjects[j].Mark << endl;
        }
        fout << "\n";
    }

    fout.close();
    cout << gNumRecs << " records saved" << endl;
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

        if (subjectFlag == (gRecs[found].NumSubjects))
            cout << "\nSubject code not found!\n";
        else
            cout << "Record " << gRecs[found].StudentNo << " Updated.\n";
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

bool ReadTextFile(const char Filename[]) { //reads text data from file to gRecs[] array
    ifstream fin;
    fin.open(Filename);
    int statusInt, i = 0;

    if(!fin.good()) {
        cout << "[DEBUG] Cant find text data file!\n" << endl;
        return false;
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

    /*for (int i = 0; i < gNumRecs; i++)
        PrintRecord(i);*/
//    PrintRecord(0);
//    PrintRecord(1);

    return true;
}

bool WriteTextFile(const char Filename[]) { //writes text data from gRecs[] to file
    ofstream fout(Filename);

    if (!fout.good()) {
        cout << "[DEBUG] Problem opening data file!\n";
        return false;
    }

    for (int i = 0; i < gNumRecs; i++) {
        fout << gRecs[i].StudentNo << endl;
        fout << gRecs[i].FirstName << " " << gRecs[i].LastName << endl;
        fout << gRecs[i].NumSubjects << endl;
        for (int j = 0; j < gRecs[i].NumSubjects; j++) {
            fout << gRecs[i].Subjects[j].Code << " ";
            fout << gRecs[i].Subjects[j].Status << " ";
            fout << gRecs[i].Subjects[j].Mark << endl;
        }
        fout << "\n";
    }

    fout.close();
    cout << gNumRecs << " records saved" << endl;
    return true;
}

bool ReadBinaryFile(const char Filename[]) { //reads binary data from file to gRecs[] array
    ifstream fin(Filename, ios::in | ios::binary);

    if (!fin.good()) {
        cout << "[DEBUG] Binary file cannot be opened for reading" << endl;
        return false;
    }

    fin.seekg(0, ios::beg);  // Move pointer to beginning of file
    int i = 0;
    while(!fin.eof()) {
        fin.read((char*)&gRecs[i], sizeof(StudentRecord));
        i++;
    }

    fin.close();
    return true;
}

bool WriteBinaryFile(const char Filename[]) { //writes binary data from gRecs[] to file
    ofstream fout(Filename, ios::binary);
    const char space = ' ';
    const char newline = '\n';

    if (!fout.good()) {
        cout << "[DEBUG] Binary file cannot be opened for writing" << endl;
        return false;
    }


    for (int i = 0; i < gNumRecs; i++) {
        /*fout.write((char*)&gRecs[i].StudentNo, sizeof(gRecs[i].StudentNo));
        fout.write(gRecs[i].FirstName, sizeof(gRecs[i].FirstName));
        fout.write(gRecs[i].LastName, sizeof(gRecs[i].LastName));
        fout.write((char*)&gRecs[i].NumSubjects, sizeof(gRecs[i].NumSubjects));

        for (int j = 0; j < gRecs[i].NumSubjects; j++) {
            fout.write(gRecs[i].Subjects[j].Code, sizeof(gRecs[i].Subjects[j].Code));
            fout.write((char*)&gRecs[i].Subjects[j].Status, sizeof(gRecs[i].Subjects[j].Status));
            fout.write((char*)&gRecs[i].Subjects[j].Mark, sizeof(gRecs[i].Subjects[j].Mark));
        }*/

        fout.write((char*)&gRecs[i], sizeof(gRecs[i]));
    }

    fout.close();
    cout << "[DEBUG] Binary write completed." << endl;

    return true;
}

void WriteBinaryRecord(char Filename[], int Pos) {
    /* This function only writes one record */
    // open the binary file (named in global cBinaryFileName)
    /*ifstream fout(Filename, ios::in | ios::binary);
    const char space = ' ';
    const char newline = '\n';

    if (!fout.good()) {
        cout << "[DEBUG] Binary file cannot be opened for writing" << endl;
        exit(1);
    }*/

    // seek() to the appropriate record at Pos


    // write the record to the binary file

    // close the file
//    fout.close();

}
