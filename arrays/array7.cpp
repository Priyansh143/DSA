// to add array as numbers
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int addArr(vector<int> arr1, vector<int> arr2){
    int s1=arr1.size();
    int s2=arr2.size();
    int num1=0;
    int num2=0;


    for (int i = 0; i <s1; i++)
    {
        num1+=arr1[i]* static_cast<int>(pow(10,s1-i-1));
    }
    for (int i = 0; i <s2; i++)
    {
        num2+=arr2[i]* static_cast<int>(pow(10,s2-i-1));
    }
    return num1+num2;
}

int main() {
    vector<int> arr1={1,2,3,0};
    vector<int> arr2={3,4};
    cout<<"sum = "<<addArr(arr1,arr2);
    return 0;
}