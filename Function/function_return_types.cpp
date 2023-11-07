#include <iostream>

#define PI 3.14159

// functions declaration

// void type
void display();
void swap(int& a, int& b);
void stringcopy(char* dest, const char* src, int srclen);

// int type
int add(const int a, const int b);
int stringlength(const char* str);

// float type
float div(const float a, const float b);

// bool type
bool isEven(const int a);

// char type
char asciiChar(int8_t n);

// char pointer type
char* str(const char* val);

// reference type
int& set(int& x);

int x = 10;

int main(int argc, char* argv[]) {

    // std::cout << "x: " << x << std::endl;

    // set(x) = 20;

    // std::cout << "x: " << x << std::endl;

    int a = 10;
    int b = 20;

    printf("a: %d, b: %d\n", a, b);

    swap(a, b);
    
    printf("a: %d, b: %d\n", a, b);

    return 0;
}

// functions definition

// void type
void display() {
    std::cout << "Hello World!" << std::endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void stringcopy(char* dest, const char* src, int srclen) {
    for (int i = 0; i < srclen; ++i) {
        dest[i] = src[i];
    }
}

// int type
int add(const int a, const int b) {
    return a + b;
}

int stringlength(const char* str) {
    int iter = 0;
    while (str[iter] != '\0') {
        iter++;
    }
    return iter;
}

// float type
float div(const float a, const float b) {
    return a / b;
}

// bool type
bool isEven(const int a) {
    if (a % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

// char type
char asciiChar(int8_t n) {
    char chr = static_cast<char>(n);
    return chr;
}


// char pointer type
char* str(const char* val) {
    char* words = new char[stringlength(val)+1];
    stringcopy(words, val, stringlength(val)+1);

    return words;
}

// reference return type
int& set(int& x) {
    return x;
}

