#include<iostream>
#include<vector>
using namespace std;

bool linSearch(int *arr,int size,int key){
    //base
    if(size==0){
        return 0;
    }
    
    if ( arr[0] == key ){
        return true;
    }
    else{
        bool remainingPart = linSearch(arr+1, size-1, key);
        return remainingPart;
    }
    
}

int main() {
    int arr[5] = {1,2,3,4,5};

    if (linSearch(arr, 5, 5))
    {
        cout << "Element Found";
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}