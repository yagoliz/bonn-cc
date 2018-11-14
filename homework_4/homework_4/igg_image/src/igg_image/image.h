// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "io_strategies/strategy.h"
#include <memory>
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
  Image(const std::shared_ptr<IoStrategy>& io_strategy){}

  Image(int rows, int cols) :
        rows_{rows}, cols_{cols}
  {
    data_.reserve(rows_ * cols_);
  }

  // Setting IoStrategy
  void SetIoStrategy(const std::shared_ptr<IoStrategy>& strategy_ptr) {
    strategy_ = strategy_ptr;
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
  std::shared_ptr<IoStrategy> strategy_ = nullptr;
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<Pixel> data_;
};

}  // namespace igg
