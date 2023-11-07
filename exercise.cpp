#include <iostream>

class Test {
    public:
        int id;
        
        Test(): id{0} {}
        Test(int _id): id{_id} {}
        ~Test() {}
}; 

void doublePointer(Test** pTest) {
    std::cout << (*pTest)->id << std::endl;
}

int main(int argc, char* argv[]) {
    Test* t1 = new Test{8};

    std::cout << t1 << std::endl;
    doublePointer(&t1);

    delete t1;

    return 0;
}
