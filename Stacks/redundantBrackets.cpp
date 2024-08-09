#include <iostream>
#include<stack>
using namespace std;

bool redundantBrackets(string &exp){
    stack<char>s;
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i]!=')')
        {
            s.push(exp[i]);
        }
        else{
            if (s.top()=='(')
            {
                return true;
            }
            else{
                bool op = false;
                while (s.top()!='(')
                {   if (s.top()=='+' ||s.top()=='-' ||s.top()=='*' ||s.top()=='/' ||s.top()=='^' ||s.top()=='%')
                    {
                        op = true;
                    }                
                    s.pop();
                }
                s.pop();
                if (!op)
                {
                    return true;
                }
                
            }         
        }       
    }
    return false;   
}


int main() {
    string exp1 = "(a + (b))";
    cout << (redundantBrackets(exp1) ? "Redundant" : "Not Redundant") << endl;

    string exp2 = "(a + b)";
    cout << (redundantBrackets(exp2) ? "Redundant" : "Not Redundant") << endl;

    string exp3 = "a + b";
    cout << (redundantBrackets(exp3) ? "Redundant" : "Not Redundant") << endl;

    string exp4 = "((a + b) + (c + d))";
    cout << (redundantBrackets(exp4) ? "Redundant" : "Not Redundant") << endl;

    string exp5 = "((a * b) + (c / d))";
    cout << (redundantBrackets(exp5) ? "Redundant" : "Not Redundant") << endl;

    string exp6 = "(a + (b * c) - d)";
    cout << (redundantBrackets(exp6) ? "Redundant" : "Not Redundant") << endl;

    string exp7 = "((a + b) * (c - d))";
    cout << (redundantBrackets(exp7) ? "Redundant" : "Not Redundant") << endl;

    string exp8 = "()";
    cout << (redundantBrackets(exp8) ? "Redundant" : "Not Redundant") << endl;

    return 0;
}