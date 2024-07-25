#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    void solve(vector<int> nums, vector <int> output, int index, vector <vector <int>> &ans ){
        //base
        if(index>=nums.size()){
            ans.push_back(output);
            return ;
        }
        //exclude
        solve(nums, output, index+1, ans);

        //include
        output.push_back(nums[index]);
        solve(nums, output, index+1, ans);
    }
    public:
    vector <vector <int>> subset(vector <int> &nums){
        vector <vector <int>> ans;
        int index=0;
        vector <int> output;
        solve(nums, output, index, ans);
        return ans;
    }

};
int main(){

    vector<int> nums={1,2,3};
    vector <vector <int>> ans;
    Solution one;
    ans=one.subset(nums);
    cout<<"{";
    for(const auto &row:ans){
        cout<<"{";
        for(int elem:row){
            cout<<elem<<" ";
        }cout<<"}, ";
    }cout<<"}";

    return 0;

}