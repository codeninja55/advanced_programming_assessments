/**********************************************************************
 * BillSystem.cpp - CSCI251/851 - Ass4 - BillSystem class definition
 * Dinh Che dbac496 23.05.2018
 **********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <set>
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
    ifstream fin;
    fin.open(fname);
    if(!fin.good()) return false;

    while(!fin.eof()) {
        string bill_type; BillRecord *tmp;
        fin>>bill_type; // read BillType
        if(fin.fail()) break;

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
int BillSystem::GetNumRecs() { return BRecs.size(); }

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
    multimap<string, BillRecord*>::iterator bill_records_iter;
    for(int i=0; i<BRecs.size(); i++) {
        string tmp;
        tmp = BRecs[i]->GetSupplier() + BRecs[i]->GetName() + BRecs[i]->GetAddress();
        bill_records_map.insert(pair<string, BillRecord*>(tmp, BRecs[i]));
    }

    for(bill_records_iter= bill_records_map.begin(); bill_records_iter != bill_records_map.end(); ++bill_records_iter) {
        // Count how many times a (supplier, name, address) key appears in multimap
        if(bill_records_map.count((*bill_records_iter).first)==3) {
            BillRecord* tmp_ptr = (*bill_records_iter).second;
            if(tmp_ptr->GetSupplier().compare("Dodo")==0) tmp_ptr->SetDiscount(0.85);
            else if(tmp_ptr->GetSupplier().compare("Alinta")==0) tmp_ptr->SetDiscount(0.8);
        }
    }
}

void BillSystem::CalcBills()
{
    for(int i=0; i<BRecs.size(); i++) { BRecs[i]->UpdateBalance(); }
}

void BillSystem::PrintReport()
{
    cout<<right<<setw(3)<<"# "<<left<<setw(14)<<"Service"<<setw(10)<<"Supplier";
    cout<<setw(20)<<"Customer"<<setw(30)<<"Address"<<right<<setw(10)<<"Bill Amount"<<endl<<endl;

    for(int i=0; i<GetNumRecs() && i<10; i++) {
        BillRecord *tmp_ptr = BRecs[i];
        cout<<right<<setw(2)<<i+1<<" "<<left<<setw(14)<<tmp_ptr->BillTypeString();
        cout<<setw(10)<<tmp_ptr->GetSupplier();
        cout<<setw(20)<<tmp_ptr->GetName()<<setw(30)<<tmp_ptr->GetAddress();
        cout<<right<<setw(10)<<fixed<<setprecision(2)<<tmp_ptr->GetBillAmount()<<endl;
    }
    cout<<endl;

    // Discounted customers
    cout<<left<<setw(24)<<"Discounted Customers"<<setw(10)<<"Supplier"<<endl;
    multimap<string, BillRecord*>::iterator disc_cust_iter = bill_records_map.begin();
    map<string, string> discounted_cust;

    for(disc_cust_iter; disc_cust_iter!=bill_records_map.end(); ++disc_cust_iter) {
        if (bill_records_map.count((*disc_cust_iter).first)==3) {
            discounted_cust.insert(pair<string, string>((*disc_cust_iter).second->GetName(), (*disc_cust_iter).second->GetSupplier()));
        }
    }

    map<string, string>::iterator iter = discounted_cust.begin();
    for(iter;iter!=discounted_cust.end();iter++) cout<<setw(24)<<(*iter).first<<setw(10)<<(*iter).second<<endl;
}

// ========== class BillSystem Private Function definitions ==========

