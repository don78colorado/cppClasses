#include <QString>
#include <QtTest>

#include "rational.h"

class RationalTest : public QObject
{
    Q_OBJECT

public:
    RationalTest();

private Q_SLOTS:
    void testCase1();
};

RationalTest::RationalTest()
{
}

void RationalTest::testCase1()
{
    QVERIFY(Rational(1,4)!=Rational(3,6));
    QVERIFY(Rational(1,2)==Rational(3,6));
    Rational oneFourth(1,4);
    Rational result;
    Rational twoFourth(2,4);
    Rational oneHalf(1,2);
    QCOMPARE(oneHalf, twoFourth);
    QVERIFY(oneHalf!=oneFourth);
    result = oneFourth * 2;
    QCOMPARE(result, twoFourth);
    result = 2 * oneFourth;
    QCOMPARE(result, twoFourth);

}

QTEST_APPLESS_MAIN(RationalTest)

#include "tst_rationaltest.moc"
