#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int> &arr, int start, int end, int key) {
    // Base case: if the start index exceeds the end index, the element is not found
    if (start > end) {
        return false;
    }

    int mid = start + (end - start) / 2;

    // Check if the mid element is the key
    if (arr[mid] == key) {
        return true;
    }
    // Recur for the left half
    else if (arr[mid] > key) {
        return binarySearch(arr, start, mid - 1, key);
    }
    // Recur for the right half
    else {
        return binarySearch(arr, mid + 1, end, key);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int key = -1;
    if (binarySearch(arr, 0, arr.size() - 1, key)) {
        cout << "Element Found";
    } else {
        cout << "Not Found";
    }

    return 0;
}
