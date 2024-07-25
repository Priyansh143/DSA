#include <iostream>
using namespace std;

// Function to print numbers from 1 to n using tail recursion
void tailRecursion(int n, int current = 1) {
    // Base case: if current is greater than n, return
    if (current > n) {
        return;
    }
    // Print the current number
    cout << current << " ";
    // Recursive call
    tailRecursion(n, current + 1);
}

int main() {
    int number = 5;
    cout << "Tail Recursion: ";
    tailRecursion(number);
    return 0;
}
