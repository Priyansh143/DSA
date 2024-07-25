#include<iostream>
#include<vector>
using namespace std;

bool possibleans(vector<int> arr, int n, int m, int mid){

    int studentCount=1;
    int pageSum=0;
    for(int i=0;i<n;i++){
        if(pageSum+arr[i]<=mid)
        {
            pageSum+=arr[i];

        }
        else{

            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            pageSum=arr[i];

        }
    }
    return true;
}
int allocateBooks(vector<int> arr, int n, int m){

    int s=0;
    int e=0;
    for(int i=0;i<n;i++){
        e+=arr[i];
    }
    int mid=s+(e-s)/2;
    int ans=-1;

    while(s<e){

        if(possibleans(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main() {
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2;  // Number of students

    int result = allocateBooks(arr, n, m);
    cout << "The minimum number of pages: " << result << endl;

    return 0;
}