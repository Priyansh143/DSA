#include <iostream>
#include<stack>
using namespace std;

int minimumCost(string str){
    stack <char> s;
    int len=0;

    if (str.size()%2 != 0)
    {
        return -1;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i]=='{')
        {
            s.push(str[i]);
        }
        else if (s.empty())
        {
            s.push(str[i]);
        }
        else{
            if (s.top()=='{')
            {
                s.pop();
                continue;
            }
            s.push(str[i]);
        }
               
    }
    int a = 0;
    int b = 0;

    while (!(s.empty()))
    {
        if (s.top()=='}')
        {
            a++;
        }
        else{
            b++;
        }
        s.pop();
        
    }
    return ((a+1)/2 + (b+1)/2);
}

int main() {
    // Test cases
    string exp1 = "}{{}}{{{";
    cout << "exp 1 Minimum Cost: " << minimumCost(exp1) << endl; // Output: 3

    string exp2 = "{{{{}}";
    cout << "exp 2 Minimum Cost: " << minimumCost(exp2) << endl; // Output: 1

    string exp3 = "}}}}";
    cout << "exp 3 Minimum Cost: " << minimumCost(exp3) << endl; // Output: 2

    string exp4 = "{}{}";
    cout << "exp 4 Minimum Cost: " << minimumCost(exp4) << endl; // Output: 0

    string exp5 = "{}{{}{}}";
    cout << "exp 5 Minimum Cost: " << minimumCost(exp5) << endl; // Output: 0

    string exp6 = "{{{{}}}}";
    cout << "exp 6 Minimum Cost: " << minimumCost(exp6) << endl; // Output: 0

    string exp7 = "{{{}}}";
    cout << "exp 7 Minimum Cost: " << minimumCost(exp7) << endl; // Output: 0

    string exp8 = "{{{{{{}}";
    cout << "exp 8 Minimum Cost: " << minimumCost(exp8) << endl; // Output: 2

    string exp9 = "{{}}{";
    cout << "exp 9 Minimum Cost: " << minimumCost(exp9) << endl; // Output: -1

    string exp10 = "}}}}{";
    cout << "exp 10 Minimum Cost: " << minimumCost(exp10) << endl; // Output: -1

    return 0;
}