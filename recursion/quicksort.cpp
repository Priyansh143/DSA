#include<iostream>
#include<array>
using namespace std;


int partition(int *arr, int s, int e){
    int key=arr[s];
    int pos=s;
    cout<<endl<<"array partition call got\n";
     for (int i = s; i <= e; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    for (int i = s; i <= e; i++)
    {
        if (arr[i]<key)
        {   
            cout<<endl<<"Throwing "<<arr[i]<<" in the correct side.";

            for(int j=i;j>s;--j){
                swap(arr[j-1],arr[j]);
            }   

            pos++;
        }
    }
    cout<<endl<<"The correct position of key "<<key<<" was found to be "<<pos<<endl;
    cout<<"after placing key element in correct place"<<endl;
    for (int i = s; i <= e; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    return pos;
    
}

void quickSort(int * arr, int s, int e){
    //base
    if (s>=e)
    {
        return;
    }
    cout<<"\nbefore partition"<<endl;
    for (int i = 0; i <= e; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    //partitioning 
    int p=partition(arr, s, e);

    cout<<"\nafter partition and before left sort"<<endl;
    for (int i = 0; i <= e; i++)
    {
        cout<<arr[i]<<" ";
    }

    //sorting left part
    quickSort(arr, s, p-1);

    cout<<"\nafter left sort and before right sort"<<endl;
    for (int i = 0; i <= e; i++)
    {
        cout<<arr[i]<<" ";
    }

    //sorting the right part
    quickSort(arr, p+1, e);
    
    cout<<"\nafter right sort"<<endl;
    for (int i = 0; i <= e; i++)
    {
        cout<<arr[i]<<" ";
    }

}

int main() {
    int arr[6]= {5,2,8,6,4,1};
    int n=6;
    quickSort(arr,0,n-1);
    cout<<endl<<"sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}