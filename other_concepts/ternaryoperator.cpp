#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;
    int max;

    if (a > b) {
        max = a;
    } else {
        max = b;
    }

    cout << "The maximum value is: " << max << endl;\

    //replacement by ternary operator
    int max = (a > b) ? a : b;

    cout << "The maximum value is: " << max << endl;
    return 0;
}
