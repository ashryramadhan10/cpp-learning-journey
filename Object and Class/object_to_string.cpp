#include <iostream>

// coordinate struct
struct Coordinate2D {
    float x;
    float y;
};

/*
*   class Point
*/
class Point {
    private:
        /*
        *   class data members
        *   ==================
        *   x: x-axis of a point
        *   y: y-axis of a point
        */
        Coordinate2D coordinate;
        char* info {nullptr};

    public:

        /*
        *   constructors
        */
        Point (): coordinate({ 0.0F, 0.0F }), info(new char[50]) {}                         // no-argument constructor

        Point (const Coordinate2D coord2d): coordinate(coord2d), info(new char[50]) {}      // one-argument constructor
        
        Point (const Point& point): coordinate(point.coordinate), info(new char[50]) {}     // copy constructor
        
        Point& operator = (const Point& point) {                                            // assignment operator overloading
            if (this == &point) {
                return *this;
            } else {
                delete [] this->info;
                this->info = new char[50];
                this->coordinate.x = point.coordinate.x;
                this->coordinate.y = point.coordinate.y;

                return *this;
            }
        }

        Point& operator = (const Coordinate2D coord2d) {                                    // assignment operator overloading
            if (this->coordinate.x == coord2d.x && this->coordinate.y == coord2d.y) {
                return *this;
            } else {
                delete [] this->info;
                this->info = new char[50];
                this->coordinate.x = coord2d.x;
                this->coordinate.y = coord2d.y;

                return *this;
            }
        }

        Point operator + (const Point pt) const {                                          // addition operator overloading
            return Point({this->coordinate.x + pt.coordinate.x, this->coordinate.y + pt.coordinate.y});
        }

        /*
        *   destructors
        */
        ~Point() {
            delete [] this->info;
        }

        /*
        *   Functionality: operator overloading of a primitive data type (char*)
        *   
        *   Arguments:
        *       - no argument
        * 
        *   Return:
        *       - char*
        */
        operator char* () const {
            sprintf(this->info, "[%.1f %.1f]", coordinate.x, coordinate.y);
            return this->info;
        }

        /*
        *   Functionality: set coordinate variable
        *   
        *   Arguments:
        *       - argument1: Coordinate2D coordinate2d = data struct of cartesian coordinate (x and y)
        * 
        *   Returns:
        *       - void
        */
       void setCoordinate(Coordinate2D coordinate2d) {
            this->coordinate = coordinate2d;
       }
};

int main(int argc, char* argv[]) {

    // initialize pt
    Point pt1({1.0F, 2.0F});

    // display point information
    // std::cout << pt1 << std::endl;
    
    // initialize pt2
    Point pt2;

    // set the coordinate of pt2
    pt2 = {2.0F, 2.0F};

    // display point information
    // std::cout << pt2 << std::endl;

    // initialize pt3
    Point pt3 = pt1 + pt2;

    // display point information
    // std::cout << pt3 << std::endl;

    Point points[] { pt1, pt2, pt3 };

    for (auto point: points) {
        std::cout << point << std::endl;
    }

    return 0;
}