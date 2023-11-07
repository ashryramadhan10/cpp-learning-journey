#include <iostream>

[[nodiscard]] int minimum(int var_a, int var_b);

int main(int argc, char* argv[]) {

    int a = 5;
    int b = 3;

    minimum(a, b);
    std::cout << "after function called!" << std::endl;

    return 0;
}

[[nodiscard]] int minimum(int var_a, int var_b) {
    return (var_a < var_b) ? var_a : var_b;
}