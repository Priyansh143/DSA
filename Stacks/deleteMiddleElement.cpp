#include <iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int n, int count){
    //base
    if (count>=(n/2))
    {   s.pop();
        return;
    }

    //recursive call
    int temp = s.top();
    s.pop();
    solve(s, n, count+1);
    s.push(temp);
    
}

void delMid(stack <int> &s, int n){
    int count = 0;
    solve(s, n, count);
    
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(7);
    s.push(9);
    cout<<"initial size: "<<s.size();
    delMid(s, s.size());

    // Print the stack to verify
    cout<<"after size: "<<s.size()<<endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}