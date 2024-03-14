#include <memory>

#include "arith.hpp"
#include "ezd.hpp"
#include "node.hpp"

namespace ezd {

Variable make_var(float x, float alpha) {
  return std::make_shared<Node>(nullptr, nullptr, x, alpha);
}

Variable operator+(Variable left, Variable right) {
  return std::make_shared<Add>(left, right);
}
Variable operator+(float left, Variable right) {
  return std::make_shared<Add>(make_var(left, 0), right);
};
Variable operator+(Variable left, float right) {
  return std::make_shared<Add>(left, make_var(right, 0));
};

Variable operator-(Variable left, Variable right) {
  return std::make_shared<Sub>(left, right);
}
Variable operator-(float left, Variable right) {
  return std::make_shared<Sub>(make_var(left, 0), right);
};
Variable operator-(Variable left, float right) {
  return std::make_shared<Sub>(left, make_var(right, 0));
};

Variable operator*(Variable left, Variable right) {
  return std::make_shared<Mul>(left, right);
}
Variable operator*(float left, Variable right) {
  return std::make_shared<Mul>(make_var(left, 0), right);
};
Variable operator*(Variable left, float right) {
  return std::make_shared<Mul>(left, make_var(right, 0));
};

Variable operator/(Variable left, Variable right) {
  return std::make_shared<Div>(left, right);
}
Variable operator/(float left, Variable right) {
  return std::make_shared<Div>(make_var(left, 0), right);
};
Variable operator/(Variable left, float right) {
  return std::make_shared<Div>(left, make_var(right, 0));
};

} // namespace ezd
