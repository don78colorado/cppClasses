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

double Rational::toDouble() const
{
    //return m_numerator / (double) m_denominator; // C style cast
    //return double(m_numerator) / m_denominator; // C style function cast
    return static_cast<double>(m_numerator) / m_denominator;
}

int Rational::numerator() const
{
    return m_numerator;
}

void Rational::setNumerator(int numerator)
{
    m_numerator = numerator;
}

const Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(rhs.numerator()*lhs.numerator(), rhs.denominator()*lhs.denominator());
}

bool operator==(const Rational &lhs, const Rational &rhs)
{
    return lhs.toDouble() == rhs.toDouble();
}

bool operator!=(const Rational &rhs, const Rational &lhs)
{
    return lhs.toDouble() != rhs.toDouble();
}
