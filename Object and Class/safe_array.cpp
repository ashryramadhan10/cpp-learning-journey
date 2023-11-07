#include <iostream>
#define LIMIT 100

class SafeArray {
private:
    int arr[LIMIT]; // initialize arr with random number or memory address LIMIT times
public:
    SafeArray() {
        // fill arr with 0
        for (int i = 0; i < LIMIT; ++i) {
            arr[i] = 0;
        }
    };
    ~SafeArray() {};

    int& operator [] (int n) {
        if (n < 0 || n >=LIMIT) {
            std::cout << "\nArray index out of bound!"; exit(1);
        } else {
            return arr[n]; // return the address of this array with setted index
        }
    }
};

int main(int argc, char* argv[]) {

    SafeArray sa;

    for (int i = 0; i < LIMIT; ++i) {
        sa[i] = i+i*10;
    }

    for (int i = 0; i < LIMIT; ++i) {
        std::cout << "\n" << sa[i];
    }

    return 0;
}