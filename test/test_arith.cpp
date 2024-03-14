#include <gtest/gtest.h>

#include "ezd.hpp"

class TestArithFixture : public testing::Test {
protected:
  ezd::Variable x;
  ezd::Variable f;

  void SetUp() {
    x = ezd::make_var(3, 0);
    f = x * x + 2.0f * x + 1.0f;
  }
};

TEST_F(TestArithFixture, forward) {
  f->forward();
  ASSERT_FLOAT_EQ(f->get(), 16);
}

TEST_F(TestArithFixture, backward) {
  f->forward();
  f->zero_grad();
  f->backward();
  ASSERT_FLOAT_EQ(x->get_grad(), 8);
}
