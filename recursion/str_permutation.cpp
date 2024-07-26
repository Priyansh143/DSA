#include <iostream>
using namespace std;
#include <vector>

void solve(string str, string output, vector<string> &ans, int index)
{

    // base
    if (index >= str.length())
    {
        ans.push_back(output);
        return;
    }
    for (int i = index; i < str.length(); i++)
    {
        if (output.find(str[i]) == string::npos)
        {
            output += str[i];
        }
        else
        {
            for (int j = 0; j < str.length(); j++)
            {
                if (output.find(str[j]) == string::npos)
                {
                    output += str[j];
                    break;
                }
            }
        }
        solve(str, output, ans, index + 1);
        output.pop_back();
    }
}

vector<string> generatePermutations(string str)
{
    vector<string> ans;
    string output;
    int index = 0;
    solve(str, output, ans, index);
    return ans;
}

int main()
{
    string input = "abcd";
    vector<string> ans;
    ans = generatePermutations(input);
    cout << "{ ";
    for (string s : ans)
    {
        cout << " {" << s << "} ";
    }
    cout << "} ";
    return 0;
}