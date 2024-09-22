#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmaller(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> arr2(n);
    s.push(-1);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (s.top() >= arr[i])
        {
            s.pop();
        }
        arr2[i]=s.top();
        s.push(arr[i]);
    }
    return arr2;
}

int main() {
    // Test case 1
    vector<int> arr1 = {4, 5, 2, 10, 8};
    vector<int> result1 = nextSmaller(arr1, arr1.size());
    cout << "Next smaller elements for {4, 5, 2, 10, 8}: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl; // Expected output: 2 2 -1 8 -1

    // Test case 2
    vector<int> arr2 = {1, 3, 2, 4};
    vector<int> result2 = nextSmaller(arr2, arr2.size());
    cout << "Next smaller elements for {1, 3, 2, 4}: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl; // Expected output: -1 2 -1 -1

    // Test case 3
    vector<int> arr3 = {5, 6, 2, 5, 9};
    vector<int> result3 = nextSmaller(arr3, arr3.size());
    cout << "Next smaller elements for {5, 6, 2, 5, 9}: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl; // Expected output: 2 2 -1 9 -1

    return 0;
}