#include <gtest/gtest.h>
#include "igg_image/image.h"
#include <vector>

using namespace igg;

TEST(TestImage, InitFromNumber) {
  Image image(512, 512);
  EXPECT_EQ(512, image.rows());
  EXPECT_EQ(512, image.cols());
}

TEST(TestImage, InitFromFile) {
  Image image;
  
  EXPECT_EQ(true, image.FillFromPgm("/home/yago/Documents/Lectures/Bonn-Modern-C++/bonn-c++/homework_2/igg_image/data/lena.ascii.pgm"));
}

TEST(TestImage, InitFromFileFail) {
  Image image;
  
  EXPECT_EQ(false, image.FillFromPgm("non existent"));
}

TEST(TestImage, ComputeHistogramSum) {
  Image image;
  image.FillFromPgm("/home/yago/Documents/Lectures/Bonn-Modern-C++/bonn-c++/homework_2/igg_image/data/lena.ascii.pgm");

  std::vector<float> histogram = image.ComputeHistogram(4);

  EXPECT_EQ(4, histogram.size());
  EXPECT_EQ(1, histogram[0] + histogram[1] + histogram[2] + histogram[3]);
}

TEST(TestImage, ComputeHistogramNoBin) {
  Image image;
  image.FillFromPgm("/home/yago/Documents/Lectures/Bonn-Modern-C++/bonn-c++/homework_2/igg_image/data/lena.ascii.pgm");

  std::vector<float> histogram = image.ComputeHistogram(0);

  EXPECT_EQ(0, histogram.size());
}