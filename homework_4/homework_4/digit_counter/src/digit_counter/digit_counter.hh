#pragma once

namespace digit {

  // Warping function
  double Warp(double number, double factor);

  // Significant digits counting
  int CountSameSignificantDigits(double a, double b);
} // namespace digit