#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr, int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[i],arr[minIndex]);
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

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}