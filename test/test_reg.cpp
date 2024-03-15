#include <gtest/gtest.h>

#include "ezd.hpp"

TEST(TestReg, converge) {
  // Constants
  ezd::Variable x = ezd::make_var(0.0f, 0.0f);
  ezd::Variable y = ezd::make_var(0.0f, 0.0f);

  // Tunables
  ezd::Variable w = ezd::make_var(1.0f);
  ezd::Variable b = ezd::make_var(1.0f);

  // Output
  ezd::Variable y_hat = w * x + b;
  ezd::Variable loss = (y_hat - y) * (y_hat - y);

  // Define line y=2x+3
  int samples = 3;
  float inputs[] = {3.0f, 7.0f, 1.0f};
  float outputs[] = {9.0f, 17.0f, 5.0f};

  const int epochs = 1000;
  for (int i = 0; i < epochs; ++i) {
    for (int j = 0; j < samples; ++j) {
      x->set(inputs[j]);
      y->set(outputs[j]);

      loss->forward();
      loss->zero_grad();
      loss->backward();
      loss->update();
    }
  }

  ASSERT_NEAR(w->get(), 2.0f, 0.001f);
  ASSERT_NEAR(b->get(), 3.0f, 0.001f);
}
