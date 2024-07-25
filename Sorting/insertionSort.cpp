#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int n)
{
    for(int i=1;i<n-1;i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>arr[i]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}