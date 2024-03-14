#ifndef ARITH
#define ARITH

#include "node.hpp"

namespace ezd {

/**
 * \brief An addition node.
 *
 * This node represents an addition operation. It is inserted into the
 * computation graph when two variables are added.
 */
class Add : public Node {
public:
  using Node::Node;
  virtual void forward();
  virtual void backward(float seed = 1);
};

/**
 * \brief A subtraction node.
 *
 * This node represents a subtraction operation. It is inserted into the
 * computation graph when two variables are subtracted.
 */
class Sub : public Node {
public:
  using Node::Node;
  virtual void forward();
  virtual void backward(float seed = 1);
};

/**
 * \brief A multiplication node.
 *
 * This node represents a multiplication operation. It is inserted into the
 * computation graph when two variables are multiplied.
 */
class Mul : public Node {
public:
  using Node::Node;
  virtual void forward();
  virtual void backward(float seed = 1);
};

/**
 * \brief A division node.
 *
 * This node represents a division operation. It is inserted into the
 * computation graph when two variables are divided.
 */
class Div : public Node {
public:
  using Node::Node;
  virtual void forward();
  virtual void backward(float seed = 1);
};

} // namespace ezd

#endif
