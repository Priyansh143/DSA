#include<iostream>
using namespace std;

int pivot(int arr[],int size){
    int s=0;
    int e=size-1;
    int m=s+(e-s)/2;

    while(s<e){
        if(arr[m]>=arr[0]){
            s=m+1;
        }
        else{
            e=m;
        }
        m=s+(e-s)/2;
    }
    return m;

}
int binarySearch(int arr[],int size, int key){

    int p=pivot(arr,size);
    int start,end;
    
    if(key >= arr[p] && key <= arr[size - 1]){
        start=p;
        end =size-1;
             
    }
    else{
        start=0;
        end=p-1;
    }

    int mid = (start + end)/2;

    while(start <= end){
        if(arr[mid] == key){
            return mid;
        }
        if(key > arr[mid]){
            start = mid+1;

        }
        else{
            end = mid-1;
        }
        mid = start+(end-start)/2;  
    }
    return -1;
}
int main()
{
    int even[6]={10,12,2,4,6,8};
    int odd[5]={3,8,10,17,1};
    int evenSearch = binarySearch(even,6,6);
    cout<<"Index of element: "<<evenSearch;
    int oddSearch = binarySearch(odd,5,8);
    cout<<"Index of element: "<<oddSearch;

}

