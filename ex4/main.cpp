/*************************************************************************
 * CSCI251 Ex4 - main1.cpp: A simple main to test the Rational class
 * <Student Name>, <login>, <date completed>
 *************************************************************************/
#include <iostream>
#include <cstring>
#include "rational.h"
using namespace std;

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

	cout << "End Rational Class Tests\n\n";
	
	return 0;
}


