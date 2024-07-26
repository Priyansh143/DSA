#include<iostream>
#include<vector>
using namespace std;

void solve(string digits, string output, int index, vector <string> &ans, string mapping[]){
    //base
    if (index>=digits.length())
    {
        ans.push_back(output);
        return;
    }
    int number= digits[index]-'0';
    string value= mapping[number];
    for (int i = 0; i < value.length(); i++)
    {
        output+=value[i];
        solve(digits, output, index+1, ans, mapping);
        output.pop_back();
    }
        
}

vector<string> letterCombinations(string digits){
    vector<string> ans;
    string output;
    int index=0;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,output, index, ans, mapping);
    return ans; 
}

int main() {
    string digits="239";
    vector<string> ans;
    ans=letterCombinations(digits);
    cout << "{ ";
    for (string s : ans)
    {
        cout << " {" << s << "} ";
    }
    cout << "} ";
    return 0;
}