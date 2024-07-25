#include<iostream>
#include<stack>

using namespace std;

int main() {
    
    stack<string> s;
    s.push("priyansh");
    s.push("kashyap");

    cout<<"top element: "<<s.top()<<endl;

    //empty, size, pop, can be performed

    return 0;
}