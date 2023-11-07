#include <iostream>
#include <string.h>

struct data {
    float m;
    float b;
};

struct pkg {
    int id;
    data pkg_data;
};

int main(int argc, char* argv[]) {

    pkg package = { 1, { 0.5f, 0.8f } };

    std::cout << "package.id: " << package.id << std::endl;
    std::cout << "package.pkg_data.m: " << package.pkg_data.m << std::endl;
    std::cout << "package.pkg_data.b: " << package.pkg_data.b << std::endl;

    return 0;
}