#include<iostream>
#include<array>
using namespace std;

int arraySum(int arr[], int size){
    //base
    if(size==1){
        return arr[0];
    }
    //recursive function
    int sum = arr[size-1]+arraySum(arr , size - 1);
    return sum;
}

int main() {
    int arr[7]={1,2,3,4,5,6,7};
    int sum=arraySum(arr,7);
    cout<<"Sum is "<<sum;
    return 0;
}