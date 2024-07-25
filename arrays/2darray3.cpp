#include <iostream>
using namespace std;

//Program to dynamically allocate memory to 2d arrays in heap

int main() {
    int rows = 3;
    int cols = 4;

    // Allocate a single contiguous block of memory
    int* data = new int[rows * cols];

    // Create an array of pointers to rows
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = &data[i * cols];
    }

    // Access and modify elements
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = i * cols + j; // Example initialization
        }
    }

    // Print the 2D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory
    delete[] data; // Only need to delete the single block
    delete[] arr; // Delete the array of pointers

    return 0;
}
