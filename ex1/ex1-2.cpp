//
// Created by codeninja on 4/03/18.
//

#include <iostream>
using namespace std;

enum Month { JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

void get_month(Month &Mth);
void print_month(Month Mth);

int main(int argc, char* argv[]) {
    Month Mth;

    cout << "Enter the month by number (e.g. January = 1): ";
    get_month(Mth);
    print_month(Mth);
    return 0;
}

void get_month(Month &Mth) {
    int inpt;
    cin >> inpt;
    Mth = Month(inpt);
}

void print_month(Month Mth) {
    switch(Mth) {
        case JAN: cout << "January" << endl; break;
        case FEB: cout << "February" << endl; break;
        case MAR: cout << "March" << endl; break;
        case APR: cout << "April" << endl; break;
        case MAY: cout << "May" << endl; break;
        case JUN: cout << "June" << endl; break;
        case JUL: cout << "July" << endl; break;
        case AUG: cout << "August" << endl; break;
        case SEP: cout << "September" << endl; break;
        case OCT: cout << "October" << endl; break;
        case NOV: cout << "November" << endl; break;
        case DEC: cout << "December" << endl; break;
    }
}
