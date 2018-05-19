/**********************************************************************
 * BillRecord.cpp - CSCI251/851 - Ass5 - BillRecord class definition
 * <Your name> <your login> <date last modified>
 **********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "BillRecord.h"
using namespace std;

// ========== class BillRecord function definitions ==========

// Default constructor
BillRecord::BillRecord()
{

}

// Reads customer details part of record from file
bool BillRecord::ReadCustDetails(ifstream &fin)
{
	//put code here for reading the customer details part of file record only into the private data members
	return true;
}

// Displays customer details part of record on screen
void BillRecord::DisplayCustDetails()
{
	//display customer details (only) from private data members
}

// Virtual fn for reading usage info part of record from file in derived classes
bool BillRecord::ReadUsageInfo(ifstream &fin)
{
	//the code here should jusy test BillType and read (eat) the usage info from file and discard it
	//later we will override this fn to read usage info into the approbriate derived classes private data members
	return true;
}


// virtual fn for displays usage info part of record in derived classes
void BillRecord::DisplayUsageInfo()
{
	// does nothing - later we will override this fn to display the appropriate billing info in the derived classes
}


// ========== Derived Class function definitions ==========


// write the function definitions of the derived classes here
