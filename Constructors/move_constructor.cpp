#include <iostream>
#include <vector>

class Test {
private:
    int* n;
public:

    // main constructor
    Test(): n{nullptr} {
        std::cout << "Test() called" << std::endl;
    }

    Test(int _n) {
        this->n = new int;
        *n = _n;
        std::cout << "Test(int _n): " << this << " called for: (" << *(this->n) << ", " << this->n << ")" << std::endl;
    }

    // copy constructor using L value
    Test(const Test& test): Test{*(test.n)} {
        std::cout << "Test(const Test& test): " << this << " called for: (" << *(this->n) << " , " << this->n << ")" << std::endl;
    }

    // move constructor using R value
    Test(const Test&& test) noexcept : n(test.n) {
        std::cout << "Test(Test&& test): " << this << " called for: (" << *(this->n) << " , " << this->n << ")" << std::endl;
        test.n = nullptr;
    }

    // destructor
    ~Test() {
        if (this->n != nullptr) {
            std::cout << "(" << *n << " , " << this->n << ") is deleted from " << this << std::endl;
        } else {
            std::cout << "nullptr is deleted from: " << this << std::endl;
        }
        delete n;
    }
    
    void displayN() {
        std::cout << "n: " << *(this->n) << std::endl;
    }
};

void rvalTest(int&& r_val) {
    std::cout << r_val << std::endl;
}

void lvalTest(int& l_val) {
    std::cout << l_val << std::endl;
}
 
int main(int argc, char* argv[]) {

    // int n = 10;

    // rvalTest(200);
    // lvalTest(n);

    // Test mTest;
    // mTest.setN(n);
    // mTest.displayN();

    // Test mTest2(mTest);
    // mTest2.displayN();

    std::vector<Test> vecTest;
    vecTest.push_back(Test{5});

    // error or nullptr
    vecTest.at(0).displayN();

    return 0;
}