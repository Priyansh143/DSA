#include <iostream>
using namespace std;

// Inline function definition
inline int square(int x) {
    return x * x;
}

int main() {
    int a = 5;
    int b = 10;

    // Calling the inline function
    cout << "Square of " << a << " is " << square(a) << endl;
    cout << "Square of " << b << " is " << square(b) << endl;

    return 0;
}
