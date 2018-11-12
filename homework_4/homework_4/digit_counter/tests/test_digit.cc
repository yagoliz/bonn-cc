#include <gtest/gtest.h>
#include <digit_counter/digit_counter.hh>

using namespace digit;

TEST(TestDigit, Warp) {
  double pi = 3.14159265;
  double factor = 1e17;

  double pi_warped = Warp(pi, factor);
  EXPECT_EQ(pi - pi_warped, 0.141593);
}

TEST(TestDigit, SignificantEqual) {
  double a = 0.34567823;
  double b = a;

  EXPECT_EQ(CountSameSignificantDigits(a, b), 100);
}

TEST(TestDigit, SignificantDifferent) {
  double a = 0.34567823;
  double b = 0.34568888;

  EXPECT_EQ(CountSameSignificantDigits(a, b), 4);
}

TEST(TestDigit, SignificantBothGreater) {
  double a = 1.34567823;
  double b = 2.34568888;

  EXPECT_EQ(CountSameSignificantDigits(a, b), -1);
}

TEST(TestDigit, OneGreater) {
  double a = 1.34567823;
  double b = 0.34568888;

  EXPECT_EQ(CountSameSignificantDigits(a, b), 0);
}

TEST(TestDigit, DifferentSigns) {
  double a = -1.000;
  double b = 1.000;

  EXPECT_EQ(CountSameSignificantDigits(a, b), 0);
}