#include <iostream>
using namespace std;

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int num = 5;
    cout << "Square of " << num << " is: " << SQUARE(num) << endl;

    int a = 10, b = 20;
    cout << "Max of " << a << " and " << b << " is: " << MAX(a, b) << endl;

    return 0;
}
