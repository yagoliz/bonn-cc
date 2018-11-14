
#include <string>
#include <gtest/gtest.h>
#include <igg_image/image.h>
#include <igg_image/io_strategies/ppm_strategy.h>

using namespace igg;

TEST(TestImage, TestValidPpmFile) {
  PpmIoStrategy strategy;
  std::string file_name = "../../data/pbmlib.ascii.ppm";

  Image image{strategy};

  EXPECT_EQ(true, image.ReadFromDisk(file_name));
  EXPECT_EQ(300, image.rows());
  EXPECT_EQ(300, image.cols());

  Image::Pixel p = image.at(299, 299);
  EXPECT_EQ(255, p.red);
  EXPECT_EQ(150, p.green);
  EXPECT_EQ(255, p.blue);
}

TEST(TestImage, TestInvalidPpmFile) {
  PpmIoStrategy strategy;
  std::string file_name = "nothing";

  Image image{strategy};

  EXPECT_EQ(false, image.ReadFromDisk(file_name));
}