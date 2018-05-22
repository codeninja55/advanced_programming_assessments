/**********************************************************************
 * BillSystem.h - CSCI251/851 - Ass4- BillSystem class declaration
 * Dinh Che dbac496 21.05.2018
 **********************************************************************/
#ifndef BILLSYS_H
#define BILLSYS_H

#include <iostream>
#include <vector>
#include "BillRecord.h"
using namespace std;


class BillSystem {

    public:
        ~BillSystem();
        bool ReadFile(char *fname);
        int GetNumRecs();
        void DisplayRec(int i); // prints ith record on screen
    private:
        vector<BillRecord*> BRecs; // vector of pointers to class BillRecord
};

#endif

