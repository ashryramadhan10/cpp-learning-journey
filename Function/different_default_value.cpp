#include <iostream>

// set default value on function prototype
[[nodiscard]] int minimum(int var_a, int var_b);

void f1(int a) {
    [[nodiscard]] int minimum(int var_a, int var_b=7);
    std::cout << minimum(a) << std::endl;
}

void f2(int a) {
    [[nodiscard]] int minimum(int var_a, int var_b=10);
    std::cout << minimum(a) << std::endl;
}

int main(int argc, char* argv[]) {

    int a = 9;

    f1(a);
    f2(a);

    return 0;
}

// function definition
[[nodiscard]] int minimum(int var_a, int var_b) {
    return (var_a < var_b) ? var_a : var_b;
}