#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    // Base case: if n is 0 or 1, factorial is 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case: n * factorial of (n-1)
    return n * factorial(n - 1);
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    // Calculate factorial using the recursive function
    int result = factorial(number);

    cout << "Factorial of " << number << " is " << result << endl;
    return 0;
}
