#include "rational.h"


Rational::Rational(int numerator, int denominator) :
    m_numerator(numerator),
    m_denominator(denominator)
{
}

int Rational::denominator() const
{
    return m_denominator;
}

void Rational::setDenominator(int denominator)
{
    m_denominator = denominator;
}

int Rational::numerator() const
{
    return m_numerator;
}

void Rational::setNumerator(int numerator)
{
    m_numerator = numerator;
}

const Rational operator*(const Rational& rhs, const Rational& lhs) {
    return Rational(rhs.numerator()*lhs.numerator(), rhs.denominator()*lhs.denominator());
}

bool operator==(const Rational &lhs, const Rational &rhs)
{
    double first, second;
    first = lhs.numerator() / (double)lhs.denominator();
    second = rhs.numerator() / (double)rhs.denominator();
    return (first==second);
}

bool operator!=(const Rational &rhs, const Rational &lhs)
{
    return !(rhs==lhs);
}
