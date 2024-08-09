#include <iostream>
#include<vector>
#include<stack>
using namespace std;

bool invalidParenthesis(string exp){

    stack<char> s;
    // char open[]={'(','{','['};
    // char close[]={'}',']',''};
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            s.push(exp[i]);
        }
        else if (exp[i]=='}')
        {
            if (s.top()=='{')
            {
                s.pop();
                continue;
            }
            else{
                return false;
            }
            
        }
        else if (exp[i]==')')
        {
            if (s.top()=='(')
            {
                s.pop();
                continue;
            }
            else{
                return false;
            }
        }
        else if (exp[i]==']')
        {
            if (s.top()=='[')
            {
                s.pop();
                continue;
            }
            else{
                return false;
            }
        }       
    }
    return s.empty();
    
}

int main() {
    // Test cases
    string exp1 = "{[()]}";
    string exp2 = "{[(])}";
    string exp3 = "((()))";
    string exp4 = "(()";

    cout << "Expression 1 is " << (invalidParenthesis(exp1) ? "valid" : "invalid") << endl;
    cout << "Expression 2 is " << (invalidParenthesis(exp2) ? "valid" : "invalid") << endl;
    cout << "Expression 3 is " << (invalidParenthesis(exp3) ? "valid" : "invalid") << endl;
    cout << "Expression 4 is " << (invalidParenthesis(exp4) ? "valid" : "invalid") << endl;

    return 0;
}