#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size) {
    // Base case: array with 0 or 1 element is already sorted
    if (size <= 1) {
        return;
    }
    
    // Perform one pass of bubble sort
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Debugging: print array state after each pass
    cout << "Array after pass with size " << size << ": ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Recursively call bubbleSort for the reduced size of the array
    bubbleSort(arr, size - 1);
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; ++i) { // Corrected loop condition
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {64, 25, 12, 22, 11};
    int size = 5; // Correct size of the array
    
    cout << "Original array: ";
    printArray(arr, size);

    bubbleSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
