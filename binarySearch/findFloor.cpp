#include <iostream>
#include <vector>
using namespace std;

int findFloor(vector<long long> &v, long long n, long long x) {
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    int i = -1;

    while (start <= end) {
        if (v[mid] == x) {
            return v[mid];
        }
        if (x > v[mid]) {
            i = mid; 
            start = mid + 1;
        } else {
            end = mid-1;
        }
        mid = start + (end - start) / 2;  
    }
    if (i != -1) {
        return v[i];
    } else {
        return -1;
    }
}

int main() {
    // Test case 1
    vector<long long> arr1 = {1, 2, 8, 10, 10, 12, 19};
    long long x1 = 5;
    cout << "Floor of " << x1 << " in arr1: " << findFloor(arr1, arr1.size(), x1) << endl; // Expected output: 2

    // Test case 2
    vector<long long> arr2 = {1, 3, 8, 10, 15};
    long long x2 = 12;
    cout << "Floor of " << x2 << " in arr2: " << findFloor(arr2, arr2.size(), x2) << endl; // Expected output: 10

    // Test case 3
    vector<long long> arr3 = {5, 10, 15, 20, 25};
    long long x3 = 5;
    cout << "Floor of " << x3 << " in arr3: " << findFloor(arr3, arr3.size(), x3) << endl; // Expected output: 5

    // Test case 4
    vector<long long> arr4 = {1, 2, 3, 4, 5};
    long long x4 = 0;
    cout << "Floor of " << x4 << " in arr4: " << findFloor(arr4, arr4.size(), x4) << endl; // Expected output: -1

    // Test case 5
    vector<long long> arr5 = {1, 2, 3, 4, 5};
    long long x5 = 6;
    cout << "Floor of " << x5 << " in arr5: " << findFloor(arr5, arr5.size(), x5) << endl; // Expected output: 5

    return 0;
}
