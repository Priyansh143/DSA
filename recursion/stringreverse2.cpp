#include<iostream>
#include<array>
using namespace std;

void reverse(string &str, int i, int j){
    //base condition
    if(i>j){
        return;
    }
    swap(str[i],str[j]);
    i++;
    j--;
    //recursive
    reverse(str,i,j);
}

int main() {
    string str = "abcde";
    cout << "Original string: " << str << endl;

    int len=str.length();

    reverse(str,0,len-1);
    cout << "Reversed string: " << str << endl;
    
    return 0;
}