#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int peakIndexMountain(vector<int> arr){
    int e= arr.size()-1;
    int s=0;
    int mid=s+(e-s)/2;

    while(s<e){
        int mid=s+(e-s)/2;
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
            
    }
    return s;
}

int main(){
    vector<int> arr={1,2,4,5,8,5,3,1};
    int ind=peakIndexMountain(arr);
    cout<<"peak:"<<ind;
    cout<<ind;


}