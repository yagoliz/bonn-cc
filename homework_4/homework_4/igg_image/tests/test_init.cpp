#include <memory>
#include <gtest/gtest.h>
#include <igg_image/image.h>
#include <igg_image/io_strategies/dummy_strategy.h>

using namespace igg;

TEST(TestImage, InitFromStrategy) {
  auto strategy = std::make_shared<DummyIoStrategy>();

  Image image;
  image.SetIoStrategy(strategy);

  EXPECT_EQ(0, image.rows());
  EXPECT_EQ(0, image.cols());
}

TEST(TestImage, InitFromStrategyAndSize) {
  auto strategy = std::make_shared<DummyIoStrategy>();

  Image image{300, 400};
  image.SetIoStrategy(strategy);

  EXPECT_EQ(300, image.rows());
  EXPECT_EQ(400, image.cols());
}

TEST(TestImage, TestReadWithStrategyNotSet) {
  std::string file_name = "../../data/river.png";

  Image image;

  EXPECT_EQ(false, image.WriteToDisk(file_name));
}

TEST(TestImage, TestWriteWithStrategyNotSet) {
  std::string file_name = "../../data/river.png";

  Image image;

  EXPECT_EQ(false, image.WriteToDisk(file_name));
}