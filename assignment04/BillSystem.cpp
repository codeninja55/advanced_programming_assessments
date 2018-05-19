/**********************************************************************
 * BillSystem.cpp - CSCI251/851 - Ass4 - BillSystem class definition
 * <Your name> <your login> <date last modified>
 **********************************************************************/
#include <iostream>
#include <fstream>
#include "BillSystem.h"
using namespace std;


// ========== class BillSystem Public Function definitions ==========

// Destructor
BillSystem::~BillSystem()
{
	//Iterate BRecs vector and delete each ptr
}

// Reads data in "usage.txt" into BRecs vector
bool BillSystem::ReadFile(char *fname)
{

	// open fname
	// if not found display: "File not found." and return 0
	// while not eof
		// allocate new memory to a temp BillRecord
		// if(!temp.ReadCustDetails(fin))break;
		// if(!temp.ReadUsageInfo(fin))break;
		// add temp to back of BRecs vector
	// close file
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
	BRecs[i]->DisplayCustDetails();
	BRecs[i]->DisplayUsageInfo();
	cout<<endl;
}

// ========== class BillSystem Private Function definitions ==========

