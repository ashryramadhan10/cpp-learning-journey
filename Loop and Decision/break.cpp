#include <iostream>

int main(int argc, char* argv[]) {
    for (int i = 0; i < 10; ++i) {
        if (i == 5)
            break;
        std::cout << i << " ";
    }
    return 0;
}