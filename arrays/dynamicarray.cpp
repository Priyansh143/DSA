#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int *arr = new int[n];  // Allocate memory for an array of 5 integers

    // Initialize the array
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    // Print the array
    cout << "Array elements: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deallocate the memory
    delete[] arr;

    return 0;
}
