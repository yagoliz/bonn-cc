#include <iostream>
#include <cmath>
#include <digit_counter/digit_counter.hh>

namespace digit {

  // Warping function definition
  double Warp(double number, double factor) {
    double tmp = number + factor;
    return (tmp - factor);
  }

  // Digit counting function definition
  int CountSameSignificantDigits(double a, double b) {
    if (a > 1 && b > 1) {
      std::cerr << "Numbers have to be smaller than 1" << std::endl;
      return -1;
    }

    int significant = 0;
    

    return significant;
  }
} // namespace digits