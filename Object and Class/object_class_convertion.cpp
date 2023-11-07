#include <iostream>

class Distance {
private:
    const float metersToFeetCoefficient; // meters to feet
    int feet;
    float inches;
public:
    Distance(): metersToFeetCoefficient(3.280833F), feet(0), inches(0.0F) {}
    Distance(float _meters): metersToFeetCoefficient(3.280833F) {
        float metersInFeet = metersToFeetCoefficient * _meters;
        feet = static_cast<int>(metersInFeet);
        inches = 12*(metersInFeet-feet);
    }
    Distance(int _feet, float _inches): feet(_feet), inches(_inches), metersToFeetCoefficient(3.280833F) {}

    void getdist() //get length from user
    {
        std::cout << "\nEnter feet: "; std::cin >> feet;
        std::cout << "Enter inches: "; std::cin >> inches;
    }

    void showdist() const //display distance
    { std::cout << feet << "\'-" << inches << "\""; }

    operator float() const {
        float fracFeet = inches / 12;
        fracFeet += static_cast<float>(feet);
        return fracFeet / metersToFeetCoefficient;
    }
};

int main(int argc, char* argv[]) {

    float mtrs;
    Distance dist1(2.35F);

    std::cout << "\ndist1 = "; dist1.showdist();

    mtrs = static_cast<float>(dist1);

    std::cout << "\ndist1 = " << mtrs << " meters\n";

    Distance dist2(5, 10.25);

    // object convertion to basic data types
    mtrs = dist2;

    std::cout << "\ndist2 = " << mtrs << " meters\n";

    return 0;
}