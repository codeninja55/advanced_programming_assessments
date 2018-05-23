/**********************************************************************
 * main.cpp - CSCI251/851 - Ass4- main() tester for class BillSystem
 * Dinh Che dbac496 21.05.2018
 **********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
#include "BillSystem.h"
using namespace std;

char Menu();

int main(){
    char fname[128];
	BillSystem BS;

    cout << "Begin tests for BillSystem\n\n";

    strncpy(fname, "usage.txt", 128);
    if(!BS.ReadFile(fname)){
        cout <<"[DEBUG] File not found in ReadFile(fname)!\n\n";
        exit(1);
    }

    int n = BS.GetNumRecs();
    cout << "Num records read: " << n << endl << endl;

    cout<<right<<setw(3)<<"# "<<left<<setw(14)<<"Service"<<setw(10)<<"Supplier";
    cout<<setw(20)<<"Customer"<<setw(30)<<"Address";
    cout<<right<<setw(10)<<"AccBal"<<setw(10)<<"Days"<<endl<<endl;

	for(int i=0; i<n && i<10; i++){
		BS.DisplayRec(i);
	}
    cout << endl;

	BS.CalcDiscounts(); // uncoment when step 3 complete
	
	BS.CalcBills();     // uncoment when step 4 complete
	BS.PrintReport();  // uncoment when step 4 complete

	cout << endl << "End tests for BillSystem\n";

	return 0;
}

