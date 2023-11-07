#include <iostream>

class Base {
private:
    int x;
public:
    Base(): x(0) {}
    Base(int ax): x(ax) {}
    virtual ~Base() {}

    virtual void info() {
        std::cout << "x: " << x << std::endl;
    }
};

class Derived: public Base {
private:
    int dx;
public:
    Derived(): dx(0) {}
    Derived(int adx): dx(adx) {}
    virtual ~Derived() {}

    virtual void info() override {
        std::cout << "dx: " << dx << std::endl;
    }
};

int main(int argc, char* argv[]) {

    Base* base = new Derived(5);

    base->info();

    delete base;
    
    return 0;
}