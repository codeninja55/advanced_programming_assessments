/*************************************************************************
 * CSCI251 Ex4 - rational.h: Declaration of Rational class
 * Dinh Che, dbac496, 15.05.18
 *************************************************************************/
#ifndef _RATIONAL_H_
#define _RATIONAL_H_
#include <iostream>
using namespace std;

class Rational {
    public:
	    Rational();  // default constructor
	    Rational(int, int); // std (initialisation) constructor
	    Rational(const Rational&); // copy constructor
        ~Rational(); // destructor
        Rational(int); // testing zero denominator constructor
	    Rational addition(const Rational&);
	    Rational subtraction(const Rational&);
	    Rational multiplication(const Rational&);
	    Rational division(Rational&);
        void printRational();
        static string divideByZeroException;
        static string zeroDenominatorException;
        static int getCount();
        friend void printRationalAsFloating(const Rational &r);

    private:
        static int count;
        int numerator;
	    int denominator;
};

#endif
