#include <iostream>

int main(int argc, char* argv[]) {

    int* a = new int[5];
    int* b = new int[5];

    for (int i = 0; i < 5; i++) {
        a[i] = i;
        b[i] = i*2;
    }

    for (int i = 0; i < 5; i++) {
        printf("a: %d, b: %d\n", a[i], b[i]);
    }

    std::cout << "\n";

    memcpy(a, b, sizeof(*b)*5);

    for (int i = 0; i < 5; i++) {
        printf("a: %d, b: %d\n", a[i], b[i]);
    }

    std::cout << a << ", " << b << std::endl;


    delete [] a;
    delete [] b;

    return 0;
}