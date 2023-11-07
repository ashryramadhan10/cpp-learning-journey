#include <iostream>

/*  PSR spot:
    --> 1. when declare a varible, we need to check the data type reliability.
        2. expression, especially the expression precedence.
        3. when defined variable at point of use, or variable that used as holder.
*/

int main(int argc, char* argv[]) {

    unsigned int goal = 10;
    unsigned int reward = 500000000;

    unsigned long long result = (goal * reward); // (goal * reward) will produce 5.000.000.000, and unsigned int max number is 4.200.000.000

    std::cout << result;

    return 0;
}