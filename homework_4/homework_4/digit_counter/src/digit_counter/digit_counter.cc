#include <iostream>
#include <cmath>
#include <digit_counter/digit_counter.hh>

namespace digit {

  // Warping function definition
  double Warp(double number, double factor) {
    number += factor;
    number -= factor;
    return number;
  }

  // Digit counting function definition
  int CountSameSignificantDigits(double a, double b) {
    if (a > 1 && b > 1) {
      std::cerr << "Numbers have to be smaller than 1" << std::endl;
      return -1;
    }
    else if (a > 1 || b > 1) {
      return 0;
    }

    int sign_a = a/std::fabs(a);
    int sign_b = b/std::fabs(b);
    if (sign_a != sign_b) {
      return 0;
    }

    a = std::fabs(a);
    b = std::fabs(b);

    int significant = 0;
    for (int i = 0; i < 100; i++) {
      double multiplied_a = a * 10.0;
      int digit_a = (int) multiplied_a;

      double multiplied_b = b * 10.0;
      int digit_b = (int) multiplied_b;

      if (digit_a != digit_b) break;

      significant++;
      a = multiplied_a - (double) (digit_a);
      b = multiplied_b - (double) (digit_b);
    }

    return significant;
  }
} // namespace digits