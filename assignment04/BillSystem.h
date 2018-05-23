/**********************************************************************
 * BillSystem.h - CSCI251/851 - Ass4- BillSystem class declaration
 * Dinh Che dbac496 23.05.2018
 **********************************************************************/
#ifndef BILLSYS_H
#define BILLSYS_H

#include <iostream>
#include <vector>
#include <map>
#include "BillRecord.h"
using namespace std;


class BillSystem {

    public:
        ~BillSystem();
        bool ReadFile(char *fname);
        int GetNumRecs();
        void DisplayRec(int i); // prints ith record on screen
        void CalcDiscounts(); // Calculate discount
        void CalcBills();  // Calculate the bill
        void PrintReport();  // Print a report
    private:
        vector<BillRecord*> BRecs; // vector of pointers to class BillRecord
        multimap<string, BillRecord*> bill_records_map; // multimap of all customer keys, pointers
        map<string, string> discounted_cust;  // map of customers with discounts only
};

#endif

