#include <iostream>
using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

int main() {
    double radius = 5.0;
    double circumference = 2 * PI * radius;

    cout << "Circumference: " << circumference << NEWLINE;

    #undef PI
    // PI is now undefined, and using it will cause a compile error.

    return 0;
}
