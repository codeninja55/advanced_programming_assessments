/*************************************************************************
 * CSCI251 Ex4 - rational.h: Declaration of Rational class
 * <Student Name>, <login>, <date completed>
 *************************************************************************/
#ifndef _RATIONAL_H_
#define _RATIONAL_H_
#include <iostream>
using namespace std;

//void printRationalAsFloating(const Rational &r);

class Rational {
  public:
	Rational();  // default constructor
	Rational(int, int); //std (initialisation) constructor
	Rational(const Rational&); //copy constructor
	Rational addition(const Rational&);
	Rational subtraction(const Rational&);
	Rational multiplication(const Rational&);
	Rational division(Rational &);
	void printRational();

  private:
	int numerator;
	int denominator;
};

#endif
