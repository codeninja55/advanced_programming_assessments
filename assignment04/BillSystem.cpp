/**********************************************************************
 * BillSystem.cpp - CSCI251/851 - Ass4 - BillSystem class definition
 * Dinh Che dbac496 21.05.2018
 **********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "BillSystem.h"
using namespace std;


// ========== class BillSystem Public Function definitions ==========

// Destructor
BillSystem::~BillSystem()
{
	//Iterate BRecs vector and delete each ptr
	for(int i=0; i < BRecs.size(); i++) { delete BRecs[i]; }
}

// Reads data in "usage.txt" into BRecs vector
bool BillSystem::ReadFile(char *fname)
{
    // open fname
    ifstream fin;
    fin.open(fname);
    // if not found display: "File not found." and return 0
    if(!fin.good()) return false;

    while(!fin.eof()) {
        string bill_type; BillRecord *tmp;
        fin>>bill_type; // read BillType
        if(fin.fail()) break;
        //tmp = new BillRecord();

        if(bill_type.compare("Elect")==0) tmp = new ElectBillRecord();
        else if(bill_type.compare("Gas")==0) tmp = new GasBillRecord();
        else tmp = new PhoneBillRecord();

        tmp->ReadCustDetails(fin);
        tmp->ReadUsageInfo(fin);   // polymorphic call to overloaded fn
        BRecs.push_back(tmp);
    }

	fin.close();
    return true;
}

// Returns the number of records in BRecs
int BillSystem::GetNumRecs()
{
	return BRecs.size();
}

 // Displays ith record on screen
void BillSystem::DisplayRec(int i)
{
	BRecs[i]->DisplayCustDetails(i);
	BRecs[i]->DisplayUsageInfo();
	cout<<endl;
}

// ========== class BillSystem Private Function definitions ==========

