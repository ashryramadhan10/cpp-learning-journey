#include <iostream>

int main(int argc, char* argv[]) {

    int x = 10;
    int* ptr = &x;
    int** dptr = &ptr;

    std::cout << ptr << " , " << &x << std::endl;

    return 0;
}