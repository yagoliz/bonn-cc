#include <string>
#include <memory>
#include <gtest/gtest.h>
#include <igg_image/image.h>
#include <igg_image/io_strategies/ppm_strategy.h>
#include <igg_image/io_strategies/png_strategy.h>

using namespace igg;

TEST(TestImage, TestDownscalePpm) {
  auto strategy = std::make_shared<PpmIoStrategy>();
  std::string file_name = "../../data/pbmlib.ascii.ppm";

  Image image;
  image.SetIoStrategy(strategy);
  image.ReadFromDisk(file_name);

  image.DownScale(2);
  EXPECT_EQ(150, image.rows());
  EXPECT_EQ(150, image.cols());  
}

TEST(TestImage, TestUpscalePpm) {
  auto strategy = std::make_shared<PpmIoStrategy>();
  std::string file_name = "../../data/pbmlib.ascii.ppm";

  Image image;
  image.SetIoStrategy(strategy);

  image.ReadFromDisk(file_name);

  image.UpScale(2);
  EXPECT_EQ(600, image.rows());
  EXPECT_EQ(600, image.cols());  
}

TEST(TestImage, TestDownscalePng) {
  auto strategy = std::make_shared<PngIoStrategy>();
  std::string file_name = "../../data/river.png";

  Image image;
  image.SetIoStrategy(strategy);

  image.ReadFromDisk(file_name);

  image.DownScale(2);
  EXPECT_EQ(800, image.rows());
  EXPECT_EQ(1200, image.cols());  
}

TEST(TestImage, TestUpscalePng) {
  auto strategy = std::make_shared<PngIoStrategy>();
  std::string file_name = "../../data/river.png";

  Image image;
  image.SetIoStrategy(strategy);

  image.ReadFromDisk(file_name);

  image.UpScale(2);
  EXPECT_EQ(3200, image.rows());
  EXPECT_EQ(4800, image.cols());  
}