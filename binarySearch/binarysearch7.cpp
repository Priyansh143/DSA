#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int midSquared = arr[mid] * arr[mid]; // Calculate square directly

        if (midSquared == key) {
            return arr[mid];
        } else if (key > midSquared) { // Compare directly with squared value
            start = mid + 1;
            ans = mid;
        } else {
            end = mid - 1;
        }
    }

    // Return the closest match found
    return ans != -1 ? arr[ans] : -1; // Return -1 if no closest match found
}

int main() {
    int even[6] = {2, 4, 6, 8, 10, 12};
    int odd[5] = {3, 6, 8, 9, 23};

    int evenSearch = binarySearch(even, 6, 10);
    cout << "Closest square root in even array: " << evenSearch << endl;

    int oddSearch = binarySearch(odd, 5, 24);
    cout << "Closest square root in odd array: " << oddSearch << endl;

    return 0;
}
