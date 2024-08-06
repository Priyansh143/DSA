#include<iostream>
#include<set>

using namespace std;

int main() {
    set<int>s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(3);
    s.insert(8);
    s.insert(2);
    for(auto i:s){
        cout<<i<<" ";
    }cout<<endl;
    s.erase(s.begin());
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl<<"5 is present or not: "<<s.count(5)<<endl;
    //find() function returns iterator of the element being searched
    set<int>::iterator it;
    it=s.find(8);

    cout<<"value in iterator: "<<*it;



    return 0;
}