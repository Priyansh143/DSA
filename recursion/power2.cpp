#include<iostream>
#include<array>
using namespace std;

//this is a optimized approach with less recursive calls

int power(int a,int b){
    //base
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    //recursive call
    int ans = power(a,b/2);

    //if b is even
    if(b%2 == 0){
        return ans * ans;
    }
    else{
        //if b is odd
        return a*ans*ans;
    }
}

int main() {

    int num,pow;
    cout<<"Enter the Number: ";
    cin>>num;
    cout<<"\n Enter Power: ";
    cin>>pow;
    cout<<"\nAnswer: "<<power(num,pow);
    return 0;
    
    return 0;
}