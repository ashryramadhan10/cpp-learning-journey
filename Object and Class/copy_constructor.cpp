/*
* Every class that has a pointer data member should include the following member functions:
*
* 1. a destructor,
* 2. a copy constructor,
* 3. operator = (assignment) overloading
*
* 1. If you don't write a destructor, your code will probably still work, but it may have storage leaks (some uses of the new operator will have no corresponding use of delete).
* 2. If you don't write a copy constructor, or you don't write operator=, your code may not work correctly; there may be attempts to dereference dangling pointers (which may cause runtime errors, or may cause garbage values to be assigned to some variables), and/or some data may be lost or corrupted.
* 3. A kind of compromise is to forbid the use of the copy constructor and the assignment of two class objects. You can do this by declaring the copy constructor and operator= as private member functions (just declaring them is enough; you do not need to write the actual code). In this case, any code that would normally cause the copy constructor or operator= to be called will instead cause a compile-time error.
*
*/

#include <iostream>
#include <cstring>

class Aclass {
    private:
        char* information {nullptr};
    public:
        Aclass(): information(new char[50]) {                   // no-argument constructor
            for (int i=0; i<50; i++) {                          
                information[i] = '\0';                          // fill it with null or \0
            }
        }
        Aclass(const Aclass& _aclass): information(new char[50]) {
            memcpy(this->information, _aclass.information, sizeof(*_aclass.information)*50);
        }
        Aclass& operator = (const Aclass& _aclass) {
            if (this == &_aclass) {                             // check for "self assignment" and do nothing in that case
                return *this;                                   // return itself
            } else {                                            // otherwise
                delete [] information;                          
                information = new char[50];                     
                memcpy(this->information, _aclass.information, sizeof(*_aclass.information)*50);

                return *this;                                   // return same object with different variable value
            }
        }
        ~Aclass() {
            delete [] information;
        }

        void setInformation(char* _information) {
            memcpy(this->information, _information, sizeof(*_information)*strlen(_information));
        }

        void displayInformation() const {
            for (int i=0; i<50; i++) {                      
                std::cout << information[i] << " ";    
            } 
            std::cout << "\n";
        }
};

int main(int argc, char* argv[]) {

    Aclass ac1;

    char ac1_info[] = {"Testing"};
    ac1.setInformation(ac1_info);
    ac1.displayInformation();

    Aclass ac2(ac1);
    ac2.displayInformation();

    char ac2_info[] = {"Testing2"};
    ac2.setInformation(ac2_info);
    ac2.displayInformation();

    ac1 = ac2;
    ac1.displayInformation();

    return 0;
}