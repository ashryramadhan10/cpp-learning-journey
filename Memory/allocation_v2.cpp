#include <iostream>

class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "Constructor called. Value: " << data << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called. Value: " << data << std::endl;
    }

    int getValue() const {
        return 1;
    }

private:
    int data;
};

int main() {
    // Allocate memory buffer
    char* buffer = new char[2 * sizeof(MyClass)];

    // Create the first object at the start of the buffer
    MyClass* obj1 = new (buffer) MyClass(42);

    // Create the second object at the address next to the first object
    MyClass* obj2 = new (buffer + sizeof(MyClass)) MyClass(24);

    // Use the objects
    std::cout << "Object 1 value: " << obj1->getValue() << std::endl;
    std::cout << "Object 2 value: " << obj2->getValue() << std::endl;

    // Manually call the destructors for both objects
    obj1->~MyClass();
    obj2->~MyClass();

    // Deallocate the memory buffer
    delete[] buffer;

    return 0;
}
