#include <iostream>
#include <memory>

class Test {
    private:
        int id;
        std::unique_ptr<int> password;
    public:
        Test(): id {0}, password {nullptr} { 
            std::cout << "Test Constructor" << std::endl; 
        }
        ~Test() { std::cout << "Test Destructor" << std::endl; }

        void password_deleter(int* password_ptr) {
            std::cout << "Custom Deleter: password" << std::endl;
            delete password_ptr;
        }
};

void test_deleter (Test* test_ptr) {
    std::cout << "Custom Deleter: Test" << std::endl;
    delete test_ptr;
}

int main(int argc, char* argv[]) {

    std::shared_ptr<Test> t_ptr { new Test(), test_deleter };
    
    return 0;
}