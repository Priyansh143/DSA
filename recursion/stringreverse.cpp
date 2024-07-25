#include<iostream>
#include<array>
using namespace std;

string revStr(string str,int len){
    string rev;
    // base 
    if(len==0){
        return string() + str[0];
    }
    //recursive func
    rev= str[len]+revStr(str,len-1);
    return rev;
}

int main() {
    string str = "abcde";
    int len=str.length();
    string rev = revStr(str,len-1);

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << rev << endl;
    
    return 0;
}