#include <iostream>

int main(int argc, char* argv[]) {

    enum DAYS { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
    DAYS today = Friday;

    switch(today) {
        case 0:
            std::cout << "Today is Monday";
            break;
        case 1:
            std::cout << "Today is Tuesday";
            break;
        case 2:
            std::cout << "Today is Wednesday";
            break;
        case 3:
            std::cout << "Today is Thursday";
            break;
        case 4:
            std::cout << "Today is Friday";
            break;
        case 5:
            std::cout << "Today is Saturday";
            break;
        case 6:
            std::cout << "Today is Sunday";
            break;
    }

    return 0;
}