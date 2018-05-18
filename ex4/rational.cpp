/*************************************************************************
 * CSCI124 Ass4 - rational.cpp: Implementation file for Rational Class
 * Dinh Che, dbac496, 15.05.18
 *************************************************************************/
#include <iostream>
#include "rational.h"
using namespace std;

int Rational::count = 0;
string Rational::divideByZeroException = "Divide by Zero Exception";
string Rational::zeroDenominatorException = "Zero Denominator Exception";

// Default constructor
Rational::Rational() : numerator(0), denominator(1)
{
    ++Rational::count;
}

// Std (initialisation) constructor
Rational::Rational(int numerator, int denominator)
{
    if (denominator == 0) throw zeroDenominatorException;
    Rational::denominator = denominator;
    Rational::numerator = numerator;
    ++Rational::count;
}

// Destructor
Rational::~Rational()
{
    --Rational::count;
}

// Copy constructor
Rational::Rational(const Rational& other)
{
    numerator = other.numerator;
    denominator = other.denominator;
    ++Rational::count;
}

// Constructor for testing divideByZeroException
Rational::Rational(int n) {
    denominator = n;
    numerator = 1;
    ++Rational::count;
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
    if (new_denominator == 0) throw divideByZeroException;
    return Rational(new_numerator, new_denominator);
}

// static accessor function to access class member count
int Rational::getCount()
{
    return Rational::count;
}

void Rational::printRational()
{
    cout<<numerator<<'/'<<denominator;
}
