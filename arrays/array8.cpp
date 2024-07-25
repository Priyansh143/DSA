// remove all occurances of a substring
#include<iostream>
#include<array>

using namespace std;

string removestr(string s,string part){
    while(s.length()!=0 && s.find(part)< s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}
int main() {
    return 0;
}