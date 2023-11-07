#include <iostream>

// set default value on function prototype
[[nodiscard]] int minimum(int var_a=7, int var_b=5);

int main(int argc, char* argv[]) {

    std::cout << minimum() << std::endl;

    return 0;
}

[[nodiscard]] int minimum(int var_a, int var_b) {

    std::cout << sizeof(var_a) << std::endl;
    std::cout << sizeof(var_b) << std::endl;

    return (var_a < var_b) ? var_a : var_b;
}