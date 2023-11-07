#include <iostream>

class Base {
private:
    int value;
public:
    Base(): value{0} {
        std::cout << "Base no-args constructor" << std::endl;
    }

    Base(int val): value{val} {
        std::cout << "Base overloading constructor" << std::endl;
    }

    Base(const Base& source): value{source.value} {
        std::cout << "Base copy constructor" << std::endl;
    }

    Base(Base&& source): value{source.value} {
        std::cout << "Base move constructor" << std::endl;
    }

    Base& operator = (const Base& rhs) {
        std::cout << "Base Assignment copy operator" << std::endl;
        if (this == &rhs) {
            return *this;
        } else {
            this->value = rhs.value;
            return *this;
        }
    }

    Base& operator = (Base&& rhs) {
        std::cout << "Base Assingment move constructor" << std::endl;
        if (this == &rhs) {
            return *this;
        } else {
            this->value = rhs.value;
            return *this;
        }
    }

    ~Base() {
        std::cout << "Based Destructor called" << std::endl;
    }
    
    int getValue() const {
        return this->value;
    }
};

class Derived: public Base {
private:
    int derived_value;
public:
    Derived(): Base(), derived_value{0} {
        std::cout << "Derived no-args constructor" << std::endl;
    }

    Derived(int val): Base{val}, derived_value{val*2} {
        std::cout << "Derived overloading constructor" << std::endl;
    }

    Derived(const Derived& source): Base{source}, derived_value{source.derived_value} {
        std::cout << "Derived copy constructor" << std::endl;
    }

    Derived(Derived&& source): Base{source}, derived_value{source.derived_value} {
        std::cout << "Derived move constructor" << std::endl;
    }

    Derived& operator = (const Derived& rhs) {
        std::cout << "Derived Assingment copy constructor" << std::endl;
        if (this == &rhs) {
            return *this;
        } else {
            Base::operator=(rhs);
            derived_value = rhs.derived_value;
            return *this; 
        }
    }

    Derived& operator = (Derived&& rhs) {
        std::cout << "Derived Assingment move constructor" << std::endl;
        if(this == &rhs) {
            return *this;
        } else {
            Base::operator=(Base{rhs.getValue()});
            derived_value = rhs.derived_value;
            return *this;
        }
    }

    ~Derived() {
        std::cout << "Derived Destructor called" << std::endl;
    }

    void displayData() const {
        std::cout << "Base value: " << this->getValue() << ", Derived value: " << derived_value << std::endl;
    }

};

int main(int argc, char* argv[]) {

    Derived d{100};
    std::cout << "d value: " << std::endl;
    d.displayData();

    Derived d1;
    d1 = Derived{300};
    std::cout << "d1 value: " << std::endl;
    d1.displayData();

    d = d1;
    std::cout << "d value: " << std::endl;
    d.displayData();

    return 0;
}