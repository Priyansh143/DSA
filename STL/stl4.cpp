#include<iostream>
#include<list>

using namespace std;

int main() {
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    //begin, empty, end, back

    l.erase(l.begin());
    cout<<"efter erase";
    for (int i:l){
        cout<<i<<" ";
    }
    cout<<"size= "<<l.size();
    //list can be copied too by previous method discussed, and can be initialized with initial size and elements

    return 0;
}