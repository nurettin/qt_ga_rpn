#include <QString>
#include <QtTest>

#include "../util.h"
#include "../wheel.h"
#include "../rpn.h"

class Tests : public QObject
{
  Q_OBJECT

public:
  Tests();

private Q_SLOTS:
  void initTestCase();
  void cleanupTestCase();
  void test_util_rand();
  void test_wheel();
  void test_rpn_eval();
};

Tests::Tests()
{
}

void Tests::initTestCase()
{
  qrg::rand_seed();
}

void Tests::test_util_rand()
{
  bool seen_min= false;
  bool seen_max= false;
  for(int n= 10000; n--;)
  {
    int r= qrg::rand_range(0, 10);
    if(r== 0) seen_min= true;
    if(r== 10) seen_max= true;
    QVERIFY2(r>= 0 && r<= 10, "Out of range");
  }
  QVERIFY2(seen_min, "Did not see min value");
  QVERIFY2(seen_max, "Did not see max value");
}

void Tests::test_wheel()
{

}

void Tests::test_rpn_eval()
{
  bool ok= true;
  QVERIFY(qrg::rpn_eval("5 7 + 6 2 - *", ok)== 48);
  QVERIFY(qrg::rpn_eval("4 5 7 2 + - *", ok)== -16);
  QVERIFY(qrg::rpn_eval("3 4 + 2  * 7 /", ok)== 2);
  QVERIFY(qrg::rpn_eval("4 2 3 5 1 - + * +", ok)== 18);
  QVERIFY(qrg::rpn_eval("4 2 + 3 5 1 - * +", ok)== 18);
}

void Tests::cleanupTestCase()
{
}

QTEST_APPLESS_MAIN(Tests)

#include "tst_tests.moc"
