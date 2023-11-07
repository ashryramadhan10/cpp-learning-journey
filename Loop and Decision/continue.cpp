#include <iostream>

int main(int argc, char* argv[]) {
    int i = 0;
    int j = 0;
    while (i < 10) {
        std::cout << i << " ";
        if (j <= 5) {
            j++;
            continue;
        }
        i++;
    }
    return 0;
}