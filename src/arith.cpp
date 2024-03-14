#include <cmath>

#include "arith.hpp"

namespace ezd {

void Add::forward() {
  Node::forward();
  x = left->get() + right->get();
}

void Add::backward(float seed) {
  grad += seed;
  left->backward(seed);
  right->backward(seed);
}

void Sub::forward() {
  Node::forward();
  x = left->get() - right->get();
}

void Sub::backward(float seed) {
  grad += seed;
  left->backward(seed);
  right->backward(-seed);
}

void Mul::forward() {
  Node::forward();
  x = left->get() * right->get();
}

void Mul::backward(float seed) {
  grad += seed;
  left->backward(seed * right->get());
  right->backward(seed * left->get());
}

void Div::forward() {
  Node::forward();
  x = left->get() / right->get();
}

void Div::backward(float seed) {
  grad += seed;
  left->backward(seed / right->get());
  right->backward(-seed * left->get() / pow(right->get(), 2));
}

} // namespace ezd
