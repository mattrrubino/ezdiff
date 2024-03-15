# EZDiff

A small [automatic differentiation](https://en.wikipedia.org/wiki/Automatic_differentiation) (AD) library implemented in C++. This library uses C++ operator overloading to automatically construct a static computation graph from mathematical expressions in source code. This graph is evaluated in the forward pass, and the gradient is computed in the backward pass using reverse accumulation AD. Detailed API reference is available on [GitHub Pages](https://mattrrubino.github.io/ezdiff/).

## Installation

This library works on Unix-based operating systems. To install it, execute the following commands:

```bash
git clone git@github.com:mattrrubino/ezdiff.git
cd ezdiff
sudo make install
```

To uninstall the library, simply run `sudo make uninstall` from the project directory.

## Usage

To use this library, you must construct expressions using the `Variable` type. These variables are assigned a value, and you use them to compute derivatives. For example, suppose you wanted to compute the derivative of the following function:

```math
f(x) = x^2 + 2x + 1
```

You could compute the derivative of this function with respect to $x$ where $x = 3$ using the following code:

```cpp
#include <iostream>
#include <ezd/ezd.h>

int main() {
    Variable x = ezd::make_var(3.0f, 0.0f);
    Variable f = x * x + 2.0f * x + 1.0f;

    f->forward();
    f->zero_grad();
    f->backward();

    // Write the derivative to standard output
    std::cout << x->get_grad() << std::endl;
}
```

For more examples, see the `test` directory. In particular, the linear regression test shows how this library can be applied to machine learning.

## Performance

This implementation prioritizes simplicity. It is readable and correct, but it is not performant. Specifically, it suffers from the following issues:

1. **Heap Allocations**\
Each node is stored using a separate heap allocation. Because computational nodes are spread throughout the heap, forward and backward passes suffer from poor cache utilization. To rememdy this, the nodes should be stored in a contiguous region of memory so that the forward and backward passes are cache-friendly.

2. **Recursion**\
The forward and backward passes are implemented recursively. This adds significant function call overhead. To remedy this, the passes should be implemented iteratively.

3. **Polymorphism**\
The behavior of the forward and backward passes are manipulated polymorphically. This adds virtual function overhead. To remedy this, the passes could be implemented with a switch.

4. **Smart Pointers**\
Memory is managed using shared pointers. This adds overhead for reference counting. To remedy this, standard pointers could be used with manual freeing.

5. **Sequential**\
This implementation is sequential. It does not leverage GPUs or SIMD instructions. Parallelizing the code would make it faster for large graphs.

