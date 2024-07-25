#include <iostream>
#include <vector>
using namespace std;

void solve(string str, vector<string> &ans, string s, int index)
{
    // base
    if (index >= str.size())
    {
        if (s.length() > 0)
        {
            ans.push_back(s);
        }
        return;
    }
    // exclude
    solve(str, ans, s, index + 1);

    // include
    s += str[index];
    solve(str, ans, s, index + 1);
}
vector<string> subsequences(string str)
{
    vector<string> ans;
    string s;
    int index = 0;
    solve(str, ans, s, index);
    return ans;
}

int main()
{
    string str = "abc";
    vector<string> ans;
    ans = subsequences(str);
    cout << "{ ";
    for (string s : ans)
    {
        cout << "{" << s << "},";
    }
    cout << "} ";
    return 0;
}