#include <iostream>

struct pkg {
    int a;
    float b;
};


int main(int argc, char* argv[]) {

    pkg package = { 1, 0.5f };

    std::cout << "package.a: " << package.a << std::endl;
    std::cout << "package.b: " << package.b << std::endl;

    package.a = 2;
    package.b = 1.5f;

    std::cout << "package.a: " << package.a << std::endl;
    std::cout << "package.b: " << package.b << std::endl;

    return 0;
}