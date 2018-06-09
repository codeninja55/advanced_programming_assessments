/**********************************************************************
 * BillRecord.cpp - CSCI251/851 - Ass5 - BillRecord class definition
 * Dinh Che dbac496 23.05.2018
 **********************************************************************/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <typeinfo>
#include "BillRecord.h"
using namespace std;

// ========== class BillRecord function definitions ==========

// Reads customer details part of record from file
bool BillRecord::ReadCustDetails(ifstream &fin)
{
    fin>>Supplier;
    fin.ignore(2, '\n');
    getline(fin, Name,'\n');
    getline(fin, Address, '\n');
    fin>>AccountBalance>>DaysSinceLastReading;
	return true;
}

// Displays customer details part of record on screen
void BillRecord::DisplayCustDetails(int i)
{
	//display customer details (only) from private data members
    cout<<right<<setw(2)<<i+1<<" "<<left<<setw(14)<<BillTypeString();
    cout<<setw(10)<<Supplier<<setw(20)<<Name<<setw(30)<<Address;
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
float BillRecord::GetDiscount() {  return Discount; }
float BillRecord::GetBillAmount() { return BillAmount; }

string BillRecord::BillTypeString()
{
    /*switch (BType) {
        case eGas: return "Gas";
        case eElect: return "Electricity";
        case ePhone: return "Phone";
    }*/
    // Refactored to use typeid() to check for type dynamically
    if(typeid(*this) == typeid(GasBillRecord)) return "Gas";
    else if(typeid(*this) == typeid(ElectBillRecord)) return "Elect";
    else if(typeid(*this) == typeid(PhoneBillRecord)) return "Phone";
    else return "Unknown Type";
}

void BillRecord::SetDiscount(float discount) { Discount = discount; }

/******************** PhoneBillRecord FUNCTION DEFINITIONS ********************/
bool ElectBillRecord::ReadUsageInfo(ifstream &fin)
{
    fin>>previous_reading>>current_reading>>rate_1>>rate_1_threshold>>rate_2>>supply_charge;
    return true;
}

void ElectBillRecord::DisplayUsageInfo()
{
    cout<<"\n"<<setw(17)<<" "<<"(Readings: "<<previous_reading<<", "<<current_reading<<" ";
    cout<<"R1: "<<rate_1<<" R1Th: "<<rate_1_threshold<<" ";
    cout<<"R2: "<<rate_2<<"SuppC: "<<supply_charge<<")";
}

void ElectBillRecord::UpdateBalance()
{
    float c = current_reading - previous_reading;
    double p = supply_charge * DaysSinceLastReading;
    BillAmount = (c<=rate_1_threshold) ?
                    (c*rate_1+p)*Discount - AccountBalance :
                    (rate_1_threshold*rate_1+(c-rate_1_threshold)*rate_2+p) * Discount - AccountBalance;
}

/******************** GasBillRecord FUNC DEFINITIONS ********************/
bool GasBillRecord::ReadUsageInfo(ifstream &fin)
{
    fin>>previous_reading>>current_reading>>heating_value>>rate>>supply_charge;
    return true;
}

void GasBillRecord::DisplayUsageInfo()
{
    cout<<"\n"<<setw(17)<<" "<<"(Readings: "<<previous_reading<<", "<<current_reading<<" ";
    cout<<"HV: "<<heating_value<<" ";
    cout<<"Rate: "<<rate<<" ";
    cout<<"SuppC: "<<supply_charge<<")";
}

void GasBillRecord::UpdateBalance()
{
    float c = current_reading - previous_reading;
    double p = supply_charge * DaysSinceLastReading;
    BillAmount = (c * heating_value * rate) * Discount - AccountBalance;
}

/******************** PhoneBillRecord FUNCTION DEFINITIONS ********************/
bool PhoneBillRecord::ReadUsageInfo(ifstream &fin)
{
    fin>>local_calls_num>>local_call_rate>>long_dist_call_time>>long_dist_call_rate>>line_rental;
    return true;
}

void PhoneBillRecord::DisplayUsageInfo()
{
    cout<<"\n"<<setw(17)<<" "<<"(LCalls: "<<local_calls_num<<", "<<local_call_rate<<" ";
    cout<<"DCalls: "<<long_dist_call_time<<", "<<long_dist_call_rate<<" ";
    cout<<"Rental: "<<line_rental<<")";
}

void PhoneBillRecord::UpdateBalance()
{
    float l = local_call_rate * local_calls_num;
    float d = long_dist_call_rate * long_dist_call_time;
    float p = line_rental * DaysSinceLastReading;
    BillAmount = (l + d + p) * Discount - AccountBalance;
}
