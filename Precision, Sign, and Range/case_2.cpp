#include <iostream>

/*  PSR spot:
        1. when declare a varible, we need to check the data type reliability.
    --> 2. expression, especially the precedence of an expression.
        3. when defined variable at point of use, or variable that used as holder.
*/

int main(int argc, char* argv[]) {

    unsigned int goal = 10;
    unsigned int coef = 1;
    unsigned int reward = 500000000;

    unsigned long long result = (goal * reward) * static_cast<unsigned long long>(coef); // the error is (goal * reward)

    std::cout << result;

    return 0;
}