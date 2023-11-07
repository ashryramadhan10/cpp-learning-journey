#include <iostream>

// function declaration
int add(const int a, const int b);

int main(int argc, char* argv[]) {

    // function call
    int result = add(1, 5);

    std::cout << "result: " << result << std::endl;

    return 0;
}

// function definition
int add(const int a, const int b) {
    return a + b;
}