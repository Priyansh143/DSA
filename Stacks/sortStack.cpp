#include <iostream>
#include <stack>
using namespace std;

void insertAtLast(stack<int> &s, int num)
{
    // base
    if (s.empty() || num > s.top())
    {
        s.push(num);
        return;
    }

    int temp = s.top();
    s.pop();
    
    // recursive call
    insertAtLast(s, num);
    s.push(temp);
}

void sortStack(stack<int> &s)
{

    // base
    if (s.empty())
    {
        return;
    }
    int top = s.top();
    s.pop();
    sortStack(s);
    insertAtLast(s, top);
}

int main()
{
    stack<int> s;
    s.push(9);
    s.push(7);
    s.push(3);
    s.push(2);
    s.push(1);
    sortStack(s);
    // Print the stack to verify
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}