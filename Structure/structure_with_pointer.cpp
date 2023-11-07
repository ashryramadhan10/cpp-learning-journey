#include <iostream>
#include <string.h>

struct package {
    unsigned int id;
    char* msg;
};

package* newPackage(const unsigned int id, const char* msg) {
    package* pkg = new package;
    pkg->id = id;
    pkg->msg = new char[strlen(msg)+1];
    strcpy(pkg->msg, msg);
    return pkg;
}

int main(int argc, char* argv[]) {

    package* pkg1 = newPackage(1, "Package 1");
    package* pkg2 = newPackage(2, "Package 2");
    package* pkg3 = newPackage(3, "Package 3");

    std::cout << "id: " << pkg1->id << ", msg: " << pkg1->msg << std::endl;

    delete[] pkg1->msg, pkg2->msg, pkg3->msg;
    delete pkg1, pkg2, pkg3;
    return 0;
}