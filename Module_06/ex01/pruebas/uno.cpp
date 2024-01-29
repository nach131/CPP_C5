#include <iostream>
#include <cfloat>
using namespace std;

int main() {
    // Declaring variables
    float a = -FLT_MAX;
    double b = NAN;

    // Printing the values of the variables
    cout << "Float value: " << a << endl;
    cout << "Double value: " << b << endl;

    return 0;
}
