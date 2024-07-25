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
int main()
{
    int even[6]={10,12,2,4,6,8};
    int odd[5]={3,8,10,17,1};
    int evenSearch = pivot(even,6);
    cout<<"Index: "<<evenSearch;
    int oddSearch = pivot(odd,5);
    cout<<"Index: "<<oddSearch<<"hello";

}

