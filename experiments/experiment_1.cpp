#include <iostream>

using namespace std;

class A {
public:
    A() { cout << "A created\n"; }
    A(const A&) { cout << "A copied\n"; }
    ~A() { cout << "A destroyed" << endl; }
};

class B{
public:
    B() { cout << "B created:" << this << "\n"; }
    B(const B&) { cout << "B copied\n"; }
    ~B() { cout << "B destroyed: " << this << "\n"; }
};

B& f() {
    A a;
    static B b;
    return b;
}

int main(int argc, char* argv[]) {

    B b = f();

    return 0;
}