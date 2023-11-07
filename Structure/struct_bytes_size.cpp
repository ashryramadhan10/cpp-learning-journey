#include <iostream>

struct size {
    short shortVar; // 2 bytes
    char charVar; // 1 bytes
    bool boolVar; // 1 bytes

    // total: 4 bytes
};

int main(int argc, char* argv[]) {

    size sizeStruct = { 1, '0', true };
    std::cout << sizeof(sizeStruct) << std::endl;

    return 0;
}