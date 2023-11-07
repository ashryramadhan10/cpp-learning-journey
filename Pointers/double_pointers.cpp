#include <iostream>

int main(int argv, char* argc[]) {

    int** arr = new int*[3];

    for (int i = 0; i < 3; i++) {
        arr[i] = new int[5];
        for (int j = 0; j < 5; j++) {
            arr[i][j] = j;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < 3; i++) {
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}