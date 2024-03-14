#ifndef EZD
#define EZD

#include <memory>

#include "node.hpp"

namespace ezd {

/**
 * \brief An automatic differentiation variable.
 *
 * This type is used as an entrypoint to the automatic differentiation engine.
 * After creating a variable, it can be used with standard C++ operators to
 * create a mathematical expression. This expression can then be automatically
 * differentiated with respect to all variables in the graph.
 */
typedef std::shared_ptr<Node> Variable;

/**
 * \brief Creates an automatic differentiation variable.
 *
 * This function is the main entrypoint to the automatic differentiation engine.
 * The returned variable can be used with standard C++ operators to create a
 * mathematical expression, and the resulting expression can be automatically
 * differentiated with respect to any node in the computational graph.
 *
 * \param x the initial variable value.
 * \param alpha the variable learning rate.
 * \return the new variable.
 */
Variable make_var(float x = 0, float alpha = 0.01);

Variable operator+(Variable left, Variable right);
Variable operator+(float left, Variable right);
Variable operator+(Variable left, float right);

Variable operator-(Variable left, Variable right);
Variable operator-(float left, Variable right);
Variable operator-(Variable left, float right);

Variable operator*(Variable left, Variable right);
Variable operator*(float left, Variable right);
Variable operator*(Variable left, float right);

Variable operator/(Variable left, Variable right);
Variable operator/(float left, Variable right);
Variable operator/(Variable left, float right);

} // namespace ezd

#endif
