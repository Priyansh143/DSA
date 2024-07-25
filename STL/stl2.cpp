#include<iostream>
#include<vector>

using namespace std;

int main() {

    vector<int> v; //inittializing empty vector
    vector<int> a(5,1); //initializes all vector of size 5 with elements all are 1, 0 by default
    cout<<"Initial capacity of the vector before storing values"<<v.capacity()<<endl;
    
    v.push_back(1);
    cout<<"Initial capacity of the vector after storing  a value "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Initial capacity of the vector after storing  a value "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Initial capacity of the vector after storing  a value "<<v.capacity()<<endl;
    cout<<"size of vector"<<v.size();

    cout<<"element at index 2"<<v.at(2)<<endl;
    cout<<"first element"<<v.front()<<endl;
    cout<<"last element"<<v.back()<<endl;

    cout<<"before pop";
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;

    v.pop_back();

    cout<<"after pop";
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;

    //to create copy of vector

    vector<int> b(a); //a is a copy of b



    return 0;
}