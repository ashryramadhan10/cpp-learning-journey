#include <iostream>
#include <vector>
#include <cstring>

class Mystring {
private:
    char* str;
public:
    // constructors
    Mystring(); // empty constructor
    Mystring(const char* str); // overloaded constructor
    Mystring(const Mystring& source); // copy constructor
    Mystring(Mystring&& source); // move constructor
    
    // destructor
    ~Mystring();

    // getters
    char* getString() const;

    Mystring& operator = (const Mystring& rhs);
    Mystring& operator = (Mystring&& rhs);
};

// no-arg constructor
Mystring::Mystring()
    : str{nullptr} {
    std::cout << "Empty constructor (" << this << ") is called!" << std::endl;
    this->str = new char[1];
    *this->str = '\0';
}

// overloading constructor
Mystring::Mystring(const char* astr)
    : str{nullptr} {
    if (astr == nullptr) { // if the declaration looks like this: Mystring{};
        this->str = new char[1];
        *this->str = '\0';
        std::cout << "Overloading constructor (" << this << ") is called!: null" <<  std::endl;
    } else {
        this->str = new char[strlen(astr)+1];
        std::strcpy(this->str, astr);
        std::cout << "Overloading constructor (" << this << ") is called!" << std::endl;
    }
}

// copy constructor
Mystring::Mystring(const Mystring& source)
    : Mystring{source.str} {
    std::cout << "Copy constructor (" << this << ") called!" << std::endl;
}

// move constructor
Mystring::Mystring(Mystring&& source)
    : str{source.str} {
    source.str = nullptr;
    std::cout << "Move constructor called from: " << this << std::endl;
}

// copy assingment operator
Mystring& Mystring::operator=(const Mystring& rhs) {
    if (this == &rhs) {
        return *this;
    } else {
        delete [] this->str;
        this->str = new char[std::strlen(rhs.str)+1];
        std::strcpy(this->str, rhs.str);

        return *this;
    }
}

// move assingment operator
Mystring& Mystring::operator=(Mystring&& rhs) {
    if(this == &rhs) {
        return *this;
    } else {
        delete [] str;
        str = rhs.str;
        rhs.str = nullptr;

        return *this;
    }
}

Mystring::~Mystring() {
    if (this->str == nullptr) {
        std::cout << "nullptr got destroyed!" << std::endl;
    } else {
        std::cout << this->str << " got destroyed!" << std::endl;
    }
    delete [] str;
}

char* Mystring::getString() const {
    return this->str;
}

void displayString(Mystring str) {
    std::cout << "str: " << str.getString() << " , will be destroyed" << std::endl;
}

int main(int argc, char* argv[]) {

    std::vector<Mystring> vecmstr;

    vecmstr.push_back(Mystring{"string1"});

    std::cout << "test" << std::endl;

    // Mystring str1 {"String1"};
    // Mystring str2{Mystring{"String2"}};

    return 0;
}