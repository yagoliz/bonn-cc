#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace igg {

class Image {
 public:
  // Constructor definition
  Image() {}
  Image(int rows, int cols): rows_{rows}, cols_{cols} {
    data_.reserve(rows * cols + 1);
  }

  // Getters for rows and cols
  int rows() const  { return rows_; }
  int cols() const  { return cols_; }

  // Declare the at() function
  const int& at(int row, int col) const;
  int& at(int row, int col);

  // Fill data vector from PGM
  bool FillFromPgm(const std::string& file_name);

  // Write data to PGM file
  void WriteToPgm(const std::string& file_name);

  // Compute the Histogram
  std::vector<float> ComputeHistogram(int bins);

  // Resizing functions
  void DownScale(int scale);
  void UpScale(int scale); 

 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg
