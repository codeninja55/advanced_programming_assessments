/**********************************************************************
 * BillRecord.h - CSCI251/851 - Ass4 - BillRecord class declaration
 * Dinh Che dbac496 21.05.2018
 **********************************************************************/
#ifndef BILLRECORD_H
#define BILLRECORD_H

#include <string>
using namespace std;

enum BillType {eElect, eGas, ePhone};

// base class...

class BillRecord {

    public:
		BillRecord();
		bool ReadCustDetails(ifstream &fin);
		void DisplayCustDetails(int);
        virtual bool ReadUsageInfo(ifstream &fin) = 0;
        virtual void DisplayUsageInfo();
    private:
        string Supplier; // Supplier's name
        string Name, Address; // Customer's name and address
        double BillAmount;// Amount in dollars and cents of this bill
    protected:
        BillType BType;
        int DaysSinceLastReading; // Days since last reading
        double AccountBalance; // Customer's account balance
};

// declare your derived classes here
//derived classes...
class ElectBillRecord : public BillRecord {

    public:
        ElectBillRecord() { BType=eElect; };
        bool ReadUsageInfo(ifstream &fin);
        void DisplayUsageInfo();
    private:
        float previous_reading, current_reading;
        double rate_1, rate_1_threshold;
        double rate_2, rate_2_threshold;
        double supply_charge;
};

class PhoneBillRecord : public BillRecord {

    public:
        PhoneBillRecord() { BType=ePhone; };
        bool ReadUsageInfo(ifstream &fin);
        void DisplayUsageInfo();
    private:
        double local_calls_num;
        float local_call_rate;
        double long_dist_call_time;
        float long_dist_call_rate;
        float line_rental;
};

class GasBillRecord : public BillRecord {

    public:
        GasBillRecord() { BType=eGas; };
        bool ReadUsageInfo(ifstream &fin);
        void DisplayUsageInfo();
    private:
        float previous_reading, current_reading;
        double heating_value;
        float rate, supply_charge;
};

#endif

