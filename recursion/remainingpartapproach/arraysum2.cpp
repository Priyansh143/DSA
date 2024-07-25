#include<iostream>
#include<array>
using namespace std;

int arraySum(int arr[], int size){
    //base
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    //recursive function
    int remainingPart= arraySum(arr+1,size-1);
    int sum= arr[0]+remainingPart;
    return sum;
}

int main() {
    int arr[7]={1,2,3,4,5,6,7};
    int sum=arraySum(arr,7);
    cout<<"Sum is "<<sum;
    return 0;
}