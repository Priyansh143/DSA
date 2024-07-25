#include<iostream>
#include<vector>
using namespace std;

bool linSearch(vector <int> &arr,int size,int key){
    //base
    if(size==0){
        if(arr[0]!=key){
            return false;
        }
        else{
            return true;
        }
    }
    //recursive func
    if(arr[size-1] == key){
        return true;
    }
    else{
        return linSearch(arr,size-1,key);
    }
    
}

int main() {
    vector <int> arr={1,2,3,4,5};
    if (linSearch(arr, arr.size(),5))
    {
        cout << "Element Found";
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}