#include<iostream>
#include<vector>
using namespace std;

//check if array is sorted & rotated like [3,4,5,1,2]

bool check(vector <int> &arr){
    
    int n = arr.size();
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[(i + 1) % n]) {
            count++;
        }
        if (count > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    
    vector<int> arr={3,4,5,1,2};
    if(check(arr)){
        cout<<"Array is sorted and Rotated";
    }
    else{
        cout<<"it's not";
    }
    return 0;
}