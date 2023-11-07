#include <iostream>

class Point {
private: 
    int x, y;
public:
    Point();
    Point(int ax, int ay);
    ~Point();

    void info() const;

    // operator overloading

    // ++ prefix
    void operator ++ ();

    // ++ postfix
    void operator ++ (int);

    // +=
    void operator += (int i);
    void operator += (Point pt);

    // -=
    void operator -= (int i);
    void operator -= (Point pt);

};

// constructor
Point::Point(): x(0), y(0) {}
Point::Point(int ax, int ay): x(ax), y(ay) {}

// destructor
Point::~Point() {}

// member functions
void Point::info() const {
    std::cout << "x: " << x << ", y: " << y << std::endl;
}

// ++ prefix
void Point::operator++() {
    ++x;
    ++y;
}

// ++ postfix
void Point::operator++(int) {
    x++;
    y++;
}

// +=
void Point::operator+=(int i) {
    x += i;
    y += i;
}

void Point::operator+=(Point pt) {
    x += pt.x;
    y += pt.y;
}

// -=
void Point::operator-=(int i) {
    x -= i;
    y -= i;
}

void Point::operator-=(Point pt) {
    x -= pt.x;
    y -= pt.y;
}

int main(int argc, char* argv[]) {

    Point pt1(10, 10);
    Point pt2(20, 20);

    pt1.info();
    pt1++;
    pt1.info();
    pt1 += 2;
    pt1.info();
    pt1 += pt2;
    pt1.info();
    pt1 -= 3;
    pt1.info();
    return 0;
}