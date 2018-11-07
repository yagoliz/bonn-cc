// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "io_strategies/strategy.h"
// #include "io_strategies/dummy_strategy.h"
// #include "io_strategies/png_strategy.h"

namespace igg {

class Image {
 public:
  /// A struct within class Image that defines a pixel.
  struct Pixel {
    int red;
    int green;
    int blue;
  };

  // Constructors
  Image(const IoStrategy& io_strategy) : strategy_{io_strategy} {}

  Image(int rows, int cols, const IoStrategy& io_strategy) :
        rows_{rows}, cols_{cols}, strategy_{io_strategy} 
  {
    data_.reserve(rows_ * cols_);
  }

  // Getter functions
  int rows() {return rows_;}
  int cols() {return cols_;}

  // Get and set pixel values
  const Pixel& at(int row, int col) const {return data_[row * cols_ + col];}
  Pixel& at(int row, int col) {return data_[row * cols_ + col];}

  // Dowscaling and Upscaling functions
  void DownScale (int scale);
  void UpScale(int scale);

  // Reading & Writing Images from disk
  bool ReadFromDisk(const std::string& file_name);
  void WriteToDisk(const std::string& file_name);

 private:
  // Private member variables
  const IoStrategy& strategy_;
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<Pixel> data_;
};

}  // namespace igg
