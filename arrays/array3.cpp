#include<iostream>
#include<array>

using namespace std;

void merge(int arr1[], int s1, int arr2[], int s2, int arr3[]) {
    int i = 0, j = 0, k = 0;

    while (i < s1 && j < s2) {
        if (arr1[i] <= arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        } else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of arr1, if any
    while (i < s1) {
        arr3[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2, if any
    while (j < s2) {
        arr3[k++] = arr2[j++];
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[5]={1,3,5,6,8};
    int arr2[3]={2,4,7};
    int arr3[8]={};
    merge(arr1,5, arr2, 3, arr3);
    print(arr3,8);

    return 0;
}