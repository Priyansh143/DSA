#include<iostream>
#include<array>

using namespace std;


int fibonacci (int num){
    //base
    if (num==0){
        return 0;
    }
    //base
    if (num==1){
        return 1;
    }
    //recursive function
    int seq= fibonacci(num-1) + fibonacci(num-2);
    return seq;

}
int main() {
    int last;
    last=fibonacci(8);
    cout<<last;
    return 0;
}