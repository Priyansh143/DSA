#include <iostream>
#include<stack>
using namespace std;

void insertAtLast(stack <int> &s, int num){
    //base
    if (s.empty())
    {   s.push(num);
        return;
    }

    //recursive call
    int temp = s.top();
    s.pop();
    insertAtLast(s, num);
    s.push(temp);   
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(7);
    s.push(9);
    insertAtLast(s, 7);
    // Print the stack to verify
    cout<<"after size: "<<s.size()<<endl;
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}