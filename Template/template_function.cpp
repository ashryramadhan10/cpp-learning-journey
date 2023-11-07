#include <iostream>

template<typename T> int find(T* array, T value, int size) {
    for (int j=0; j<size; j++)
        if (array[j] == value)
            return j;
    return -1;
}

template<typename T> T add(T& a, T& b) {
    return a + b;
}

int main(int argc, char* argv[]) {

    char arrOfChar[5] = {'A', 'B', 'C', 'D', 'E'};
    char value = 'D';
    int size = sizeof(arrOfChar) / sizeof(arrOfChar[0]);

    int index = find(arrOfChar, value, size);

    std::cout << "index: " << index << "\n";

    int a = 7;
    int b = 2;

    std::cout << add(a, b) << "\n";

    return 0;
}