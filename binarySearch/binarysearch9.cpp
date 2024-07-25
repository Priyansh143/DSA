//aggresive cows
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool possibleans(vector<int> arr, int c, int m){

    int cowCount=1;    
    int lastPos=arr[0];
    int s=arr.size();
    for(int i;i<s;i++){
    
        if(arr[i]-lastPos>=m){
            cowCount++;
            if(cowCount==c){
                return true;
            }
            lastPos=arr[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> arr, int c){
    sort(arr.begin(),arr.end());
    int s=0;
    int ans=-1;
    int e = arr.back() - arr.front();
    while(s<=e){
        int m=s+(e-s)/2;

        if(possibleans(arr, c, m)){
            ans=m;
            s=m+1;
        } 
        else{
            e=m-1;
        }
    }

    return ans;

}

int main() {
    vector<int> arr = {1, 2, 4, 8, 9};
    int c = 3; // Number of cows
    cout << "Largest minimum distance: " << aggressiveCows(arr, c) << endl;

    return 0;
}