#include <iostream>

/*  PSR spot:
        1. when declare a varible, we need to check the data type reliability.
        2. expression, especially the expression precedence.
    --> 3. when defined variable at point of use, or variable that used as holder.
*/

int main(int argc, char* argv[]) {

    unsigned int goal = 10;
    unsigned int reward = 500000000;

    unsigned int result = (goal * static_cast<unsigned long long>(reward)); // the error is unsigned int result

    std::cout << result;

    return 0;
}