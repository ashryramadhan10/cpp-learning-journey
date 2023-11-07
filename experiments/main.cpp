#include <iostream>
#include <memory>

using namespace std;

template <class T>
class Test {
private:
    T data;
public:
    Test() : data(nullptr) {}
    
    Test(T _data) {
        cout << "move constructor called" << endl;
        data = _data;
    }

    T getData() const {
        return this->data;
    }
};

int main() {
    
    Test<int>* mTest = new Test<int>(3); 
    cout << (*(mTest)).getData() << endl;
    return 0;
}
