#include <memory>

#include "node.hpp"

namespace ezd {

float Node::get() { return x; }

void Node::set(float x) { this->x = x; }

std::shared_ptr<Node> Node::get_left() { return left; }

std::shared_ptr<Node> Node::get_right() { return right; }

float Node::get_grad() { return grad; }

void Node::zero_grad() {
  grad = 0;
  if (left)
    left->zero_grad();
  if (right)
    right->zero_grad();
}

void Node::update(bool minimize) {
  x += alpha * grad * (minimize ? -1 : 1);
  if (left)
    left->update(minimize);
  if (right)
    right->update(minimize);
}

void Node::forward() {
  if (left)
    left->forward();
  if (right)
    right->forward();
}

void Node::backward(float seed) {
  grad += seed;
  if (left)
    left->backward(seed);
  if (right)
    right->backward(seed);
}

Node::~Node() {}

Node::Node(std::shared_ptr<Node> left, std::shared_ptr<Node> right, float x,
           float alpha) {
  this->x = x;
  this->alpha = alpha;
  this->left = left;
  this->right = right;
}

} // namespace ezd
