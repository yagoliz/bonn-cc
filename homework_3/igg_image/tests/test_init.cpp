#include <gtest/gtest.h>
#include <igg_image/image.h>
#include <igg_image/io_strategies/dummy_strategy.h>

using namespace igg;

TEST(TestImage, InitFromStrategy) {
  DummyIoStrategy strategy;

  Image image{strategy};
  EXPECT_EQ(0, image.rows());
  EXPECT_EQ(0, image.cols());
}

TEST(TestImage, InitFromStrategyAndSize) {
  DummyIoStrategy strategy;

  Image image{300, 400, strategy};
  EXPECT_EQ(300, image.rows());
  EXPECT_EQ(400, image.cols());
}