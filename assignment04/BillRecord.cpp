/**********************************************************************
 * BillRecord.cpp - CSCI251/851 - Ass5 - BillRecord class definition
 * <Your name> <your login> <date last modified>
 **********************************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "BillRecord.h"
using namespace std;

// ========== class BillRecord function definitions ==========

// Reads customer details part of record from file
bool BillRecord::ReadCustDetails(ifstream &fin)
{
	// put code here for reading the customer details part of file record only
	// into the private data members
    fin>>Supplier;
    fin.ignore(2, '\n');
    getline(fin, Name,'\n');
    getline(fin, Address, '\n');
    fin>>AccountBalance;
    fin>>DaysSinceLastReading;

	return true;
}

// Displays customer details part of record on screen
void BillRecord::DisplayCustDetails(int i)
{
	//display customer details (only) from private data members
    cout<<right<<setw(2)<<i+1<<" ";
    cout<<left<<setw(8)<<Supplier<<setw(20)<<Name<<setw(30)<<Address;
    cout<<right<<setw(10)<<AccountBalance<<setw(10)<<DaysSinceLastReading;
}

// Virtual fn for reading usage info part of record from file in derived classes
bool BillRecord::ReadUsageInfo(ifstream &fin) { }

// virtual fn for displays usage info part of record in derived classes
void BillRecord::DisplayUsageInfo() { }

// Accessor functions for private data
string BillRecord::GetSupplier() { return Supplier; }
string BillRecord::GetName() { return Name; }
string BillRecord::GetAddress() { return Address; }

void BillRecord::SetDiscount(float discount) { Discount = discount; }

/******************** PhoneBillRecord FUNCTION DEFINITIONS ********************/
bool ElectBillRecord::ReadUsageInfo(ifstream &fin)
{
    fin>>previous_reading>>current_reading>>rate_1>>rate_1_threshold>>rate_2>>rate_2_threshold;
    return true;
}

void ElectBillRecord::DisplayUsageInfo()
{
    cout<<"\n(Readings: "<<previous_reading<<", "<<current_reading<<" ";
    cout<<"R1: "<<rate_1<<" R1Th: "<<rate_1_threshold<<" ";
    cout<<"R2: "<<rate_2<<" R2Th: "<<rate_2_threshold<<" ";
    cout<<"SuppC: "<<supply_charge<<")";
}

/******************** GasBillRecord FUNC DEFINITIONS ********************/
bool GasBillRecord::ReadUsageInfo(ifstream &fin)
{
    fin>>previous_reading>>current_reading>>heating_value>>rate>>supply_charge;
    return true;
}

void GasBillRecord::DisplayUsageInfo()
{
    cout<<"\n(Readings: "<<previous_reading<<", "<<current_reading<<" ";
    cout<<"HV: "<<heating_value<<" ";
    cout<<"Rate: "<<rate<<" ";
    cout<<"SuppC: "<<supply_charge<<")";
}

/******************** PhoneBillRecord FUNCTION DEFINITIONS ********************/

bool PhoneBillRecord::ReadUsageInfo(ifstream &fin)
{
    fin>>local_calls_num>>local_call_rate>>long_dist_call_time>>long_dist_call_rate>>line_rental;
    return true;
}

void PhoneBillRecord::DisplayUsageInfo()
{
    cout<<"\n(LCalls: "<<local_calls_num<<", "<<local_call_rate<<" ";
    cout<<"DCalls: "<<long_dist_call_time<<", "<<long_dist_call_rate<<" ";
    cout<<"Rental: "<<line_rental<<")";
}
