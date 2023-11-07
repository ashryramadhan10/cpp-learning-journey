#include <iostream>

int main(int argc, char* argv[]) {

    constexpr uint16_t numRows {3};
    constexpr uint16_t numCols {3};

    int* intArray2d[numRows] = {nullptr}; // first pointer pointing to nullptr

    for (int i = 0; i < numRows; i++) {
        *(intArray2d + i) = new int[numCols];

        for (int j = 0; j < numCols; j++) {
            *(*(intArray2d + j * i)) = numRows * i + j;

            std::cout << *(intArray2d + j * i) << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < numRows; i++) {
        delete [] intArray2d[i];
    }
    return 0;
}