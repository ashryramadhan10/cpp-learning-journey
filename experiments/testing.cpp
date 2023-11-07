#include <iostream>

class Test {
private:
    int* val;
public:
    // empty constructor
    Test(): val{nullptr} {}

    // overload constructor
    Test(const int val) {
        this->val = new int;
        *this->val = val;
        std::cout << "Overload Constructor called, val address: " << this->val << std::endl;
    }

    // copy constructor
    Test(const Test& test): Test{*(test.val)} {
        std::cout << "Copy Constructor called" << std::endl;
    }

    // overloadding assignment operator
    Test& operator=(const Test& test) {
        std::cout << "Overloadding assingment operator called" << std::endl;
        if (this == &test) {
            return *this;
        } else {
            delete this->val;
            this->val = new int;
            *this->val = *(test.val);

            return *this;
        }
    }

    // destructor
    ~Test() {
        if (this->val != nullptr) {
            std::cout << "this id: " << *(this->val) << ", var_address: (" << this->val << ") has been deleted, ins_address: " << this << std::endl;
        } else {
            std::cout << "nullptr is deleted from: " << this << std::endl;
        }
        delete val;
    }

    // member functions
    void displayValue() const {
        std::cout << "Value: " << *this->val << std::endl;
    }

    // getters
    int getValue() const {
        return *(this->val);
    }
};

void displayData(const Test test) {
    std::cout << "Value: " << test.getValue() << std::endl;
}

int main(int argc, char* argv[]) {

    Test mTest {10};
    displayData(mTest);

    std::cout << "\nmTest value: " << mTest.getValue() << std::endl;

    return 0;
}