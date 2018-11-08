// File to test the main functions

#include <iostream>
#include "igg_image/image.h"
#include "igg_image/io_strategies/png_strategy.h"
#include "igg_image/io_strategies/ppm_strategy.h"

int main() {
  // Let's check the PNG strategy
  std::string file_name = "../data/river.png";
  igg::PngIoStrategy strategy;

  // Create image data object
  igg::Image image{strategy};

  // Read the file 
  if (!(image.ReadFromDisk(file_name))) {
    std::cout << "Error reading file" << std::endl;
    return 1;
  }

  // If writing is successful we can try different things

  // Red filter
  std::string file_name_red = "../data/riverred.png";
  for (int i = 0, rows = image.rows(); i < rows; i++) {
    for (int j = 0, cols = image.cols(); j < cols; j++) {
      igg::Image::Pixel p {image.at(i, j)};
      image.at(i, j) = igg::Image::Pixel{p.red, p.blue, p.green};
    }
  }

  image.WriteToDisk(file_name_red);

  // Downscale image
  std::string file_name_small = "../data/riversmall.png";
  image.DownScale(2);
  image.WriteToDisk(file_name_small);

  // Upscale image
  std::string file_name_big = "../data/riverbig.png";
  image.UpScale(4);
  image.WriteToDisk(file_name_big);

// --------------------------------------------------------
  // Time to test PPM strategy
  std::string file_ppm = "../data/pbmlib.asii.ppm";
  igg::PpmIoStrategy strategy_ppm; 

  // Create ppm image object
  igg::Image image_ppm{strategy_ppm};

  // Read the file 
  if (!(image_ppm.ReadFromDisk(file_ppm))) {
    std::cout << "Error reading file" << std::endl;
    return 1;
  }

  // Change the image
  std::string file_ppm_red = "../data/pbmlib.ascii.red.ppm";
  for (int i = 0, rows = image_ppm.rows(); i < rows; i++) {
    for (int j = 0, cols = image_ppm.cols(); j < cols; j++) {
      igg::Image::Pixel p {image_ppm.at(i, j)};
      image_ppm.at(i, j) = igg::Image::Pixel{p.red, p.green, p.blue};
    }
  }

  image_ppm.WriteToDisk(file_ppm_red);

  // End of main
  return 0;
}