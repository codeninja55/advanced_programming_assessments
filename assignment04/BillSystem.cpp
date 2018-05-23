/**********************************************************************
 * BillSystem.cpp - CSCI251/851 - Ass4 - BillSystem class definition
 * Dinh Che dbac496 21.05.2018
 **********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <map>
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

// Calculate the discount for Dodo and Alinta Records
void BillSystem::CalcDiscounts()
{
    multimap<string, BillRecord*> bill_records_map;
    multimap<string, BillRecord*>::iterator bill_records_iter;
    for(int i=0; i<BRecs.size(); i++) {
        string tmp, address;
        tmp = BRecs[i]->GetSupplier() + BRecs[i]->GetName() + BRecs[i]->GetAddress();
        bill_records_map.insert(pair<string, BillRecord*>(tmp, BRecs[i]));
    }
    for(bill_records_iter= bill_records_map.begin(); bill_records_iter != bill_records_map.end(); ++bill_records_iter) {
        // Count how many times a (supplier, name, address) key appears in multimap
        int count = bill_records_map.count((*bill_records_iter).first);
        if(count==3) {
            BillRecord* tmp_ptr = (*bill_records_iter).second;
            if(tmp_ptr->GetSupplier().compare("Dodo")==0) tmp_ptr->SetDiscount(0.75);
            else if(tmp_ptr->GetSupplier().compare("Alinta")==0) tmp_ptr->SetDiscount(0.8);
        }
    }
}

// ========== class BillSystem Private Function definitions ==========

