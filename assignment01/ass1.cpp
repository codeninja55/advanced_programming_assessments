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
//void ReadBinaryRecord(const char FileName[], int Pos);

// TODO Ask Koren why you cannot use a const char[] when you have a param for char[]

// ============= Public Function Definitions =========================

// Reads data file into array
void ReadFile() {
    if(!ReadBinaryFile(cBinaryFileName)) {
        if (ReadTextFile(cTextFileName)) WriteBinaryFile(cBinaryFileName);
        else cout << "[DEBUG] Unable to read both binary and text file." << endl;
    }
    /* Uncomment to reset the binary file to the original data */
//    ReadTextFile(cTextFileName);
//    WriteBinaryFile(cBinaryFileName);
}

// Displays specified record on screen
void DisplayRecord() {
    int studentNoInput;

    cout << "Enter student number: ";
    cin >> studentNoInput;
    int found = FindRecord(studentNoInput);

    if (found < 0) cout << "/nRecord not found" << endl;
    else PrintRecord(found);
}

// Writes array to text data file
void SaveFile() {
    if (!WriteBinaryFile(cBinaryFileName)) {  // Attempt to write to binary file first.
        ofstream fout;
        fout.open(cTextFileName);
        if (!fout.good()) {
            cout << "[DEBUG] Problem opening data file!\n";
            exit(1);
        }

        // Loops through and passes each struct attr to the file stream
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
        cout << gNumRecs << " records saved." << endl;
    }
}

// Updates status or mark of specified subject of specified student number
void UpdateRecord() {
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

        bool subjectFoundFlag = false;

        // Loops through the students subject structs to find the one requested
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

                    // Conditional to print the new status based on input
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
                } else if (strncmp(editOption, "m", 1) == 0) {  // Allows update of mark
                    int newMark;
                    cout << "Enter new mark: ";
                    cin >> gRecs[found].Subjects[j].Mark;
                    cout << gRecs[found].Subjects[j].Code << " Mark (new): " << gRecs[found].Subjects[j].Mark;
                } else {
                    cout << "\nIncorrect choice!\n\n";
                }
                subjectFoundFlag = true;
            }
        }

        if (!subjectFoundFlag)  // Checks if the subject was found and prints message to user
            cout << "\nSubject code not found!\n";
        else {
            /* If it's zero, the seekp(will start from zero) */
            WriteBinaryRecord(cBinaryFileName, found);
            cout << "\nRecord " << gRecs[found].StudentNo << " Updated.\n";
        }
    }
}

// ============= Private Function Definitions =========================

// Prints record i on screen
void PrintRecord(int i) {
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

// Returns index of matching record or -1 if not found
int FindRecord(long StudentNo) {
    for (int i = 0; i < gNumRecs; i++)
        if (gRecs[i].StudentNo == StudentNo) return i;
	return -1;
}

// Reads text data from file to gRecs[] array
bool ReadTextFile(const char Filename[]) {
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
    return true;
}

// Writes text data from gRecs[] to file
bool WriteTextFile(const char Filename[]) {
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

// Reads binary data from file to gRecs[] array
bool ReadBinaryFile(const char Filename[]) {
    streampos fileSize;
    ifstream fin(Filename, ios::in | ios::binary | ios::ate);  // Opening file with cursor placed at end

    if (!fin.good()) {
        cout << "[DEBUG] Binary file cannot be opened for reading" << endl;
        return false;
    }

    /*int i = 0;
    while(!fin.eof()) {
        fin.read((char*)&gRecs[i], sizeof(StudentRecord));
        i++;
    }*/

    // fin.seekg(0, ios::end);  // Not used because starting the stream at the end when opening
    fileSize = fin.tellg();
    cout << fileSize / sizeof(StudentRecord) << " records read from binary file." << endl;

    fin.seekg(0, ios::beg);
    fin.read((char*)&gNumRecs, sizeof(gNumRecs));  // Read and move cursor past the number of records stored (i.e. 4 bytes)
    /* Because an array is also sequential in memory,
     * we can use a larger size of read to input the whole array */
    while(!fin.eof())
        fin.read((char*)&gRecs, cMaxRecs*sizeof(StudentRecord));
    fin.close();

    return true;
}

// Writes binary data from gRecs[] to file
bool WriteBinaryFile(const char Filename[]) {
    ofstream fout(Filename, ios::binary);

    if (!fout.good()) {
        cout << "[DEBUG] Binary file cannot be opened for writing" << endl;
        return false;
    }

    fout.write((char*)&gNumRecs, sizeof(gNumRecs));

    // Much less efficient
    // for (int i = 0; i < gNumRecs; i++) {
    //     /*fout.write((char*)&gRecs[i].StudentNo, sizeof(gRecs[i].StudentNo));
    //     fout.write(gRecs[i].FirstName, sizeof(gRecs[i].FirstName));
    //     fout.write(gRecs[i].LastName, sizeof(gRecs[i].LastName));
    //     fout.write((char*)&gRecs[i].NumSubjects, sizeof(gRecs[i].NumSubjects));
    //
    //     for (int j = 0; j < gRecs[i].NumSubjects; j++) {
    //         fout.write(gRecs[i].Subjects[j].Code, sizeof(gRecs[i].Subjects[j].Code));
    //         fout.write((char*)&gRecs[i].Subjects[j].Status, sizeof(gRecs[i].Subjects[j].Status));
    //         fout.write((char*)&gRecs[i].Subjects[j].Mark, sizeof(gRecs[i].Subjects[j].Mark));
    //     }*/
    //     fout.write((char*)&gRecs[i], sizeof(gRecs[i]));
    // }
    fout.write((char*)&gRecs, sizeof(StudentRecord) * gNumRecs);

    fout.close();
    cout << gNumRecs << " records saved to binary file." << endl;

    return true;
}

// Writes one gRecs[] record to the binary file
void WriteBinaryRecord(const char Filename[], int Pos) {
    // open the binary file (named in global cBinaryFileName)
    ofstream fout(Filename, ios::in | ios::binary);

    if (!fout.good()) {
        cout << "[DEBUG] Binary file cannot be opened for writing" << endl;
        exit(1);
    }

    // seekp() past the first 4 bytes which stores gNumRecs
    fout.seekp(sizeof(gNumRecs), ios::beg);

    // seekp() to the appropriate record at Pos
    fout.seekp(Pos*sizeof(gRecs[Pos]), ios::cur);

    PrintRecord(Pos);
    // write the record to the binary file
    fout.write((char*)&gRecs[Pos], sizeof(StudentRecord));

    // close the file
    fout.close();
//    ReadBinaryRecord(cBinaryFileName, Pos);
}

// This function is for testing reading a specific StudentRecord from the binary file.
/*void ReadBinaryRecord(const char FileName[], int Pos) {
    ifstream fin(FileName, ios::binary);
    StudentRecord tempStudent;

    fin.seekg(sizeof(gNumRecs), ios::beg);
    fin.seekg(Pos*sizeof(gRecs[Pos]), ios::cur);
    fin.read((char*)&tempStudent, sizeof(tempStudent));

    cout << "\nTemp Student Binary Read" << endl;

    cout << "\nStudent No. " << tempStudent.StudentNo << endl
         << "First Name: " << tempStudent.FirstName << endl
         << "Last Name: " << tempStudent.LastName << endl
         << "Subjects (" << tempStudent.NumSubjects << "):" << endl;

    for (int j = 0; j < tempStudent.NumSubjects; j++) {
        cout << "  " << tempStudent.Subjects[j].Code << " ";

        switch (tempStudent.Subjects[j].Status) {
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
        cout << " " << tempStudent.Subjects[j].Mark << endl;
    }

    fin.close();
}*/
