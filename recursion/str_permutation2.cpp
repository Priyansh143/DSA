#include <iostream>
using namespace std;
#include <vector>

void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
    // base
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, ans, index + 1);
        // backtrack
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> generatePermutations(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    ans = generatePermutations(arr);
    cout << "{ ";
    for (const auto &row : ans)
    {   cout<< "{ ";
        for (int elem : row)
        {
            cout<< elem ;
        }cout<< "} ";
    }
    cout << "} ";
    return 0;
}