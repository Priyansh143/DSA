#include<iostream>
#include<array>

using namespace std;

int main() {

    int basic[3]={1,2,3};
    array<int,3> a ={1,2,3};

    int size=a.size();
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<endl;

    }

    cout<<"/n Element at index 2= "<<a.at(2)<<endl;
    cout<<"to check if array is empty or not: "<<a.empty()<<endl;
    cout<<"First element"<<a.front()<<endl;
    cout<<"Last element"<<a.back()<<endl;
    

    return 0;
}
