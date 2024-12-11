#include <iostream>
#include <vector>
#include <functional>

// Define the templated function
template <typename Func>
auto adapt_function(Func f) {
    return [f](int n, auto... args) {
        std::vector<float> vec = {static_cast<float>(args)...};
        return f(n, vec);
    };
}

// Example function to be adapted
float example_function(int n, const std::vector<float>& vec) {
    float sum = 0;
    for (const auto& v : vec) {
        sum += v;
    }
    return sum * n;
}

int main() {
    // Adapt the example function
    auto adapted_function = adapt_function(example_function);

    // Use the adapted function
    std::cout << adapted_function(2, 1.0f, 2.0f, 3.0f) << std::endl; // Output should be 12.0

    return 0;
}

