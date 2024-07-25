#include<iostream>
#include<queue>

using namespace std;

int main() {
    queue <string> s;

    s.push("priyansh");
    s.push("fuckin");
    s.push("kashyap");
    s.pop();
    cout<<s.front();

    //front, pop, size,empty 

    return 0;
}