#include <iostream>

int main(int argc, char* argv[]) {

    const int MUL_3 = 0x1;
    const int MUL_5 = 0x1 << 1;
    const int MUL_7 = 0x1 << 2;
    const int MUL_9 = 0x1 << 3;

    std::cout << MUL_3 << std::endl;
    std::cout << MUL_5 << std::endl;
    std::cout << MUL_7 << std::endl;
    std::cout << MUL_9 << std::endl;

    std::cout << "===\n"; 

    std::cout << (MUL_3 | MUL_5) << std::endl;
    std::cout << (MUL_3 | MUL_7) << std::endl;
    std::cout << (MUL_3 | MUL_9) << std::endl;

    std::cout << (MUL_5 | MUL_7) << std::endl;
    std::cout << (MUL_5 | MUL_9) << std::endl;

    std::cout << (MUL_7 | MUL_9) << std::endl;
}