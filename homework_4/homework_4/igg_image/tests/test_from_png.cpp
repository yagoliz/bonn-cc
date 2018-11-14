
#include <string>
#include <gtest/gtest.h>
#include <igg_image/image.h>
#include <igg_image/io_strategies/png_strategy.h>

using namespace igg;

TEST(TestImage, TestValidPngFile) {
  PngIoStrategy strategy;
  std::string file_name = "../../data/river.png";

  Image image{strategy};

  EXPECT_EQ(true, image.ReadFromDisk(file_name));
  EXPECT_EQ(1600, image.rows());
  EXPECT_EQ(2400, image.cols());
}

TEST(TestImage, TestInvalidPngFile) {
  PngIoStrategy strategy;
  std::string file_name = "nothing";

  Image image{strategy};

  EXPECT_ANY_THROW(image.ReadFromDisk(file_name));
}