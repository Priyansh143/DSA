#include<iostream>
#include<array>
using namespace std;

void merge(int *arr, int s, int e){
    int mid= s + (e-s)/2;
    int len1= mid-s+1;
    int len2= e-mid;
    int *first=new int[len1];
    int *second=new int[len2];
    int mainArrayIndex=s;

    for (int i = 0; i < len1; i++)
    {
        first[i]=arr[mainArrayIndex++];
    }
    // mainArrayIndex=mid+1;
    for (int i = 0; i < len2; i++)
    {   
        second[i]=arr[mainArrayIndex++];
    }
    mainArrayIndex=s;
    int i=0;
    int j=0;
    while(i < len1 && j< len2){
        if (first[i]<second[j])
        {
            arr[mainArrayIndex++]=first[i++];
        }
        else{
            arr[mainArrayIndex++]=second[j++];
        }
        
    }
    while(i<len1){
        arr[mainArrayIndex++]=first[i++];
    }
    while(j<len2){
        arr[mainArrayIndex++]=second[j++];
    }
}

void mergeSort(int *arr, int s, int e){
    //base
    if (s>=e){
        return;
    }
    int mid=s + (e-s)/2;
    //sorting left side
    mergeSort(arr, s, mid);
    //sorting right side
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);
}

int main() {
    int arr[6]={5,2,8,6,5,1};
    int n=6;
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}