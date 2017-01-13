#ifndef RATIONAL_H
#define RATIONAL_H


class Rational
{
    int m_numerator;
    int m_denominator;
public:
    Rational(int numerator = 0, int denominator = 1);

    int numerator() const;
    void setNumerator(int numerator);
    int denominator() const;
    void setDenominator(int denominator);

    double toDouble() const;
};

const Rational operator*(const Rational& lhs, const Rational& rhs);
bool operator==(const Rational& rhs, const Rational& lhs);
bool operator!=(const Rational& rhs, const Rational& lhs);

#endif // RATIONAL_H
