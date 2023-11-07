#include <iostream>

int stringLength(const char* str) {
    int iter = 0;
    while(str[iter] != '\0') {
        iter++;
    }
    return iter;
}

void stringCopy(char* dst, const char* src) {
    int i;
    for(i = 0; i < stringLength(src)+1; ++i) {
        dst[i] = src[i];
    }
    dst[i] = '\0';
}

class Person {
private:
    // private data members
    int id;
    char* name;
    bool isAlive;

public:
    // public data members
    static int speciesId;

    // constructor
    Person(): id(0), name(NULL), isAlive(false) {
        // empty constructor
    }

    Person(const int aid, const char* aname, const bool aisAlive): id(aid), isAlive(aisAlive) {
        name = new char[stringLength(aname)+1];
        stringCopy(name, aname);
    }

    // destructor
    ~Person() {
        delete [] name;
    }

    void displayProfile() const {
        std::cout << "Id: " << id << std:: endl;
        std::cout << "Name: " << name << std:: endl;
        std::cout << "isAlive: " << isAlive << std:: endl;
    }

    // getters function
    int getId() const {
        return id;
    }

    char* getName() const {
        return name;
    }

    bool getLiveStatus() const {
        return isAlive;
    }
};

// initialization of Person static data members (speciesId)
int Person::speciesId = 1;

int main(int argc, char* argv[]) {

    Person** persons = new Person*[3];

    for (int i = 0; i < 3; ++i) {

        // local scope variable (variable defined at point of use)
        char* temp = new char[8];
        sprintf(temp, "name_%d", i);

        // global variable
        persons[i] = new Person(i, temp, true);

        // delete temp variable
        delete [] temp;
    }

    // display profile for each person
    for (int i = 0; i < 3; ++i) {
        persons[i]->displayProfile();
        printf("\n");
    }

    // dealocate memory for every person
     for (int i = 0; i < 3; ++i) {
        delete persons[i];
    }

    // dealocate memory for persons
    delete [] persons;

    // point persons to NULL to avoid runtime error
    persons = NULL;

    return 0;
}