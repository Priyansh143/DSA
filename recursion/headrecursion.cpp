#include <iostream>
using namespace std;

// Function to print numbers from n to 1 using head recursion
void headRecursion(int n) {
    // Base case: if n is less than 1, return
    if (n < 1) {
        return;
    }
    // Recursive call
    headRecursion(n - 1);
    // Print the number after the recursive call
    cout << n << " ";
}

int main() {
    int number = 5;
    cout << "Head Recursion: ";
    headRecursion(number);
    return 0;
}
