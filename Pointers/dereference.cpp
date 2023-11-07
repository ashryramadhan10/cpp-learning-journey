#include <iostream>

class collection {
public:
    int x;
    float y;

    collection(): x{0}, y{0.0} {
        std::cout << "Empty constructor called: " << this << std::endl;
    }

    collection(const collection& cltn): x{cltn.x}, y{cltn.y} {
        std::cout << "Copy constructor called: " << this << std::endl;
    }
    ~collection() {
        std::cout << "Dectructor called: " << this << std::endl;
    }
};

int main(int argc, char* argv[]) {

    int collSize = 3;
    int* intArr = new int[collSize];
    collection* arr = new collection[collSize];

    for (int i = 0; i < collSize; i++) {

        intArr[i] = i;

        arr[i].x = i;
        arr[i].y = i + 0.5f;
        
        std::cout << "intArr[" << i << "]: " << *(intArr + i) << std::endl;
        std::cout << "X: " << (*(arr + i)).x << std::endl;
    }

    delete [] arr;
    delete [] intArr;

    return 0;
}