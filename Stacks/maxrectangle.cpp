#include <iostream>
#include<vector>
#include<stack>
using namespace std;

vector <int> prev(vector <int> arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> arr2;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= s.top())
        {
            s.pop();
        }
        arr2[i]=s.top();
        s.push(arr[i]);    
    }
    
} 

int main() {
    
    return 0;
}