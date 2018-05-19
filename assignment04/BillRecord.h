/**********************************************************************
 * BillRecord.h - CSCI251/851 - Ass4 - BillRecord class declaration
 * <Your name> <your login> <date last modified>
 **********************************************************************/
#ifndef BILLRECORD_H
#define BILLRECORD_H

#include <string>
using namespace std;

enum BillType {eElect, eGas, ePhone };

// base class...

class BillRecord {
  public:
	BillRecord();
	bool ReadCustDetails(ifstream &fin);
	bool ReadUsageInfo(ifstream &fin);
	void DisplayCustDetails();
	void DisplayUsageInfo();

  private:
  	BillType BType;
	string Supplier; // Supplier's name
	string Name, Address; // Customer's name and address
	double AccountBalance; // Customer's account balance
	int DaysSinceLastReading; // Days since last reading
	double BillAmount;// Amount in dollars and cents of this bill
};

//derived classes...

// declare your derived classes here


#endif

