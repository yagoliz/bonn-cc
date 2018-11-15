#include <memory>
#include <string>
#include <gtest/gtest.h>
#include <igg_image/image.h>
#include <igg_image/io_strategies/png_strategy.h>

using namespace igg;

TEST(TestImage, TestValidPngFile) {
  auto strategy = std::make_shared<PngIoStrategy>();
  std::string file_name = "../../data/river.png";

  Image image;
  image.SetIoStrategy(strategy);

  EXPECT_EQ(true, image.ReadFromDisk(file_name));
  EXPECT_EQ(1600, image.rows());
  EXPECT_EQ(2400, image.cols());
}

TEST(TestImage, TestInvalidPngFile) {
  auto strategy = std::make_shared<PngIoStrategy>();
  std::string file_name = "nothing";

  Image image;
  image.SetIoStrategy(strategy);

  EXPECT_ANY_THROW(image.ReadFromDisk(file_name));
}