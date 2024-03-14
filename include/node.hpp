#ifndef NODE
#define NODE

#include <memory>

namespace ezd {

/**
 * \brief A node in a computation graph.
 *
 * This class is used to represent a step in a computation. Operators on the
 * node type are overloaded to create new nodes, automatically constructing a
 * graph out of arbitrary mathematical expressions.
 */
class Node {
public:
  /**
   * \brief Returns the value of the node.
   *
   * \return the value as a float.
   */
  float get();

  /**
   * \brief Sets the value of the node.
   *
   * \param x the desired value.
   */
  void set(float x);

  /**
   * \brief Returns the left child of the node.
   *
   * \return the left child node.
   */
  std::shared_ptr<Node> get_left();

  /**
   * \brief Returns the right child of the node.
   *
   * \return the right child node.
   */
  std::shared_ptr<Node> get_right();

  /**
   * \brief Returns the derivative of the node.
   *
   * \return the derivative as a float.
   */
  float get_grad();

  /**
   * \brief Clears the derivative of this node and all descendants.
   */
  void zero_grad();

  /**
   * \brief Updates the value of this node and all descendants via the gradient.
   *
   * \param minimize indicates whether to minimize (true) or maximize (false).
   */
  void update(bool minimize = true);

  /**
   * \brief Performs a forward pass.
   *
   * The forward pass recurses through the computational graph, and each node
   * stores its output value after the operation completes.
   */
  virtual void forward();

  /**
   * \brief Performs a backward pass.
   *
   * The backward pass recurses through the computational graph, and each node
   * stores its derivative with respect to the source node after the operation
   * completes.
   *
   * \param seed the derivative seed.
   */
  virtual void backward(float seed = 1);

  /**
   * \brief Virtual destructor.
   */
  virtual ~Node();

  /**
   * \brief Node constructor.
   *
   * \param left the left child node.
   * \param right the right child node.
   * \param x the initial node value.
   * \param alpha the node learning rate.
   */
  Node(std::shared_ptr<Node> left = nullptr,
       std::shared_ptr<Node> right = nullptr, float x = 0, float alpha = 0);

protected:
  /** The value of the node. */
  float x;

  /** The derivative of the node. */
  float grad;

  /** The learning rate of the node. */
  float alpha;

  /** The left child of the node. */
  std::shared_ptr<Node> left;

  /** The right child of the node. */
  std::shared_ptr<Node> right;
};

} // namespace ezd

#endif
