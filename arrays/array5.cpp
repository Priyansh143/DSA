#include<iostream>
#include<vector>

using namespace std;

void rotateArray(vector <int> &arr, int key){

    vector<int> temp(arr.size());

    for (int i=0; i<arr.size();i++){

        temp[(i+key)%arr.size()]=arr[i];
    }
    arr=temp;
}

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};

    cout << "Original array: ";
    printArray(arr);

    rotateArray(arr,3);

    cout << "Array after moving zeroes: ";
    printArray(arr);

    return 0;
}