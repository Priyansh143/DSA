#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool issafe(int newx, int newy, int n, vector<vector<int>> &m, vector<vector<int>> &visited) {
    return (newx >= 0 && newx < n && newy >= 0 && newy < n && visited[newx][newy] == 0 && m[newx][newy] == 1);
}

void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> &visited, string path) {
    // base case
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    // mark the cell as visited
    visited[x][y] = 1;

    // Down
    int newx = x + 1;
    int newy = y;
    if (issafe(newx, newy, n, m, visited)) {
        path.append("D");
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Left
    newx = x;
    newy = y - 1;
    if (issafe(newx, newy, n, m, visited)) {
        path.append("L");
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Right
    newx = x;
    newy = y + 1;
    if (issafe(newx, newy, n, m, visited)) {
        path.append("R");
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Up
    newx = x - 1;
    newy = y;
    if (issafe(newx, newy, n, m, visited)) {
        path.append("U");
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // backtrack: unmark the cell as visited
    visited[x][y] = 0;
}

vector<string> findpath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    if (m[0][0] == 0) {
        return ans;
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    solve(m, n, ans, 0, 0, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = 4;
    vector<string> ans = findpath(m, n);
    for (const string &s : ans) {
        cout << s << " ";
    }
    return 0;
}
