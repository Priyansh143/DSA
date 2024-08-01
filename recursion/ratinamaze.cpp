#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool issafe(int newx, int newy,int n,  vector<vector<int>> &m, vector <vector<int>> &visited){

    bool flag= false;

    if ((newx>=0 && newx<n) && (newy>=0 && newy<n) && visited[newx][newy] == 0 && m[newx][newy] == 1)
    {
        flag= true;
    }
    return flag;

}

void solve(vector<vector<int>> &m, int n, vector<string>&ans, int x, int y, vector <vector<int>> &visited, string path){
    //base
    if (x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }
    //mark the cell as visited
    visited[x][y]=1;

    //down
    int newx= x+1;
    int newy= y;
    if (issafe(newx, newy, n, m, visited)){
        path.append("D");
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //left
    newx= x;
    newy= y-1;
    if (issafe(newx, newy, n, m, visited)){
        path.append("L");
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //right
    newx= x;
    newy= y+1;
    if (issafe(newx, newy, n, m, visited)){
        path.append("R");
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();

    }


    //up
    newx= x-1;
    newy= y;
    if (issafe(newx, newy, n, m, visited)){
        path.append("U");
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    
    visited[x][y]=0;
    
}

vector <string> findpath(vector<vector<int>> &m, int n){
    vector<string>ans;
    if (m[0][0]==0)
    {
        return ans;
    }
    
    int srcx=0;
    int srcy=0;
    vector <vector<int>> visited = m;
    //initialize with 0
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j]=0;
        }
        
    }
    string path = "";
    solve(m,n,ans, srcx,srcy, visited, path);
    sort(ans.begin(),ans.end());
    return ans;
    
}
int main() {
    vector<vector<int>> m={{1,0,0,0},{1,1,1,1},{1,0,1,1},{1,1,1,1}};
    int n= 4;
    vector <string> ans = findpath(m, n);
    for(string s:ans){
        cout<<s<<"  ";
    }
    return 0;
}