/*************************************************************************
 * CSCI124 Ass4 - rational.cpp: Implementation file for Rational Class
 * Used by: <Student Name>, <login>, <date completed>
 *************************************************************************/
#include <iostream>
#include "rational.h"
using namespace std;

// Default constructor
Rational::Rational() : numerator(0), denominator(1) { }

// Std (initialisation) constructor
Rational::Rational(int numerator, int denominator)
{
    Rational::denominator = denominator;
    Rational::numerator = numerator;
}

// Destructor
//Rational::~Rational() { }

// Copy constructor
Rational::Rational(const Rational& other)
{
    numerator = other.numerator;
    denominator = other.denominator;
}

// Overloaded Assignment operator
//Rational::operator=(const Rational& rOperand) {}

Rational Rational::addition(const Rational& other)
{
    int new_numerator = (numerator * other.denominator) + (other.numerator * denominator);
    int new_denominator = denominator * other.denominator;
    return Rational(new_numerator, new_denominator);
}

Rational Rational::subtraction(const Rational& other)
{
    int new_numerator = (numerator * other.denominator) - (other.numerator * denominator);
    int new_denominator = denominator * other.denominator;
    return Rational(new_numerator, new_denominator);
}

Rational Rational::multiplication(const Rational& other)
{
    int new_numerator = numerator * other.numerator;
    int new_denominator = denominator * other.denominator;
    return Rational(new_numerator, new_denominator);
}

Rational Rational::division(Rational& other)
{
    int new_numerator = numerator * other.denominator;
    int new_denominator = denominator * other.numerator;
    return Rational(new_numerator, new_denominator);
}

void Rational::printRational()
{
    cout<<numerator<<'/'<<denominator;
}
