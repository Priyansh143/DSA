#include <iostream>
#include <vector>
using namespace std;

int firstOccur(const vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;
    int first = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            first = mid;
            end = mid - 1;  // Look on the left side for the first occurrence
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return first;
}

int lastOccur(const vector<int>& arr, int key) {
    int start = 0;
    int end = arr.size() - 1;
    int last = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            last = mid;
            start = mid + 1;  // Look on the right side for the last occurrence
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return last;
}
pair <int,int> firstAndLast(vector<int>&arr,int key){
    pair<int,int>p;
    p.first=firstOccur(arr,key);
    p.second=lastOccur(arr,key);
    return p;
}
int main() {
    vector<int> even = {1, 2, 3, 3, 3, 3, 4, 5};
    int foccur=firstAndLast(even,3).first;
    int loccur=firstAndLast(even,3).second;
    cout << "First occurrence index: " << foccur << endl;
    cout << "Last occurrence index: " << loccur << endl;

    return 0;
}
