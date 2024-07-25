#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;
    int c = 15;
    int max;

    if (a > b) {
        if (a > c) {
            max = a;
        } else {
            max = c;
        }
    } else {
        if (b > c) {
            max = b;
        } else {
            max = c;
        }
    }

    cout << "The maximum value is: " << max << endl;

    //replacement
    int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

    cout << "The maximum value is: " << max << endl;
    return 0;
}
