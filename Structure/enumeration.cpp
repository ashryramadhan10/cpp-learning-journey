#include <iostream>

int main (int argc, char* argv[]) {

    enum DAYS { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
    DAYS day = Saturday;

    std::cout << "Enum day value: " << day << std::endl;
    return 0;
}