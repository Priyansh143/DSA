#include<iostream>
#include<array>
using namespace std;

int power(int num, int pow){
    // base
    if ( pow == 0){
        return 1;
    }
    //recursive
    return num*power(num,pow-1);
}

int main() {
    int num,pow;
    cout<<"Enter the Number: ";
    cin>>num;
    cout<<"\n Enter Power: ";
    cin>>pow;
    cout<<"\nAnswer: "<<power(num,pow);
    return 0;
}