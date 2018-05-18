/*************************************************************************
 * CSCI251 Ex4 - main1.cpp: A simple main to test the Rational class
 * Dinh Che, dbac496, 15.05.18
 *************************************************************************/
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "rational.h"
using namespace std;

bool exception_test = true;

int main()
{
	cout << "Begin Rational Class Tests\n\n";

	cout<<"Testing default constructor: ";
	Rational n1;
	n1.printRational();
	cout << endl << endl;

	cout<<"Testing std constructor: ";
   	Rational n2(1,2);
	n2.printRational();
	cout << endl << endl;

	cout<<"Testing copy constructor: ";
   	Rational n3(n2);
	n3.printRational();
	cout << endl << endl;

	cout<<"Testing addition: ";
	n1 = n2.addition(n3);
	n2.printRational();
	cout <<" + ";
	n3.printRational();
	cout <<" = ";
	n1.printRational();
	cout << endl << endl;

	cout<<"Testing addition 2: ";
	Rational n4(1, 4);
	Rational n5(1, 4);
	n1 = n4.addition(n5);
	n4.printRational();
	cout <<" + ";
	n5.printRational();
	cout <<" = ";
	n1.printRational();
	cout << endl << endl;

	cout<<"Testing subtraction: ";
	n1 = n2.subtraction(n3);
	n2.printRational();
	cout <<" - ";
	n3.printRational();
	cout <<" = ";
	n1.printRational();
	cout << endl << endl;

	cout<<"Testing multiplication: ";
	n1 = n2.multiplication(n3);
	n2.printRational();
	cout <<" * ";
	n3.printRational();
	cout <<" = ";
	n1.printRational();
	cout << endl << endl;

	cout<<"Testing division: ";
	n1 = n2.division(n3);
	n2.printRational();
	cout <<" / ";
	n3.printRational();
	cout <<" = ";
	n1.printRational();
	cout << endl << endl;

    cout<<"Testing printRationalAsFloating: ";
    n1.printRational();
    cout<<" as floating ";
    printRationalAsFloating(n1);
    cout << endl << endl;

    cout<<"Testing count: ";
    cout<<Rational::getCount();
    cout << endl << endl;

    if (exception_test) {
        cout<<"Testing Exceptions: "<<endl;
        try {
            cout<<"Zero Denominator std constructor: "<<endl;
            Rational n6(1, 0);
        } catch (string err) {
            cerr<<"[ERROR]: \nWhat: "<<err<<endl;
            //exit(1);
        }

        try {
            Rational n7(0);
            cout<<"Divide by Zero Exception for printRationalAsFloating(): "<<endl;
            printRationalAsFloating(n7);
        } catch (string err) {
            cout<<"[ERROR]: \nWhat: "<<err<<endl;
            //exit(1);
        }

        try {
            Rational n8(0, 1);
            cout<<"Divide by Zero Exception for Rational::division(): "<<endl;
            n1.division(n8);
        } catch (string err) {
            cout<<"[ERROR]: \nWhat: "<<err<<endl;
            //exit(1);
        }
        cout << endl << endl;
    }

	cout << "End Rational Class Tests\n\n";
	
	return 0;
}

void printRationalAsFloating(const Rational &r)
{
    if (r.denominator == 0) throw Rational::divideByZeroException;
    else cout<<(float)(r.numerator / r.denominator);
}

