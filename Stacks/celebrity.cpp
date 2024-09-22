#include <iostream>
#include<vector>
#include<stack>
using namespace std;

bool knows(vector< vector <int>>& M, int a, int b){
    if (M[a][b]==1)
    {
        return true;
    }
    else{
        return false;
    }
    
}

int celebrity(vector< vector <int>>& M, int n ){
    stack<int>s;

    //pushing all elements to stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    //potential candidates
    while (s.size()>1)
    {
        int a= s.top();
        s.pop();
        int b= s.top();
        s.pop();
        if (knows(M,a,b))
        {
            s.push(b);
        }
        else{
            s.push(a);
        }       
    }
    
    int candidate= s.top();

    //checking if candidate's row is filled w 0
    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i]!=0)
        {
            return -1;
        }
    }

    //checking

    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][candidate]==1)
        {
            oneCount++;
        }
    }
    if (oneCount != n-1)
    {
        return -1;
    }
    
    return candidate;
}


int main() {
    // Test case 1: Celebrity exists
    vector<vector<int>> M1 = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n1 = 3;
    cout << "Celebrity in Test Case 1: " << celebrity(M1, n1) << endl; // Expected Output: 1

    // Test case 2: No celebrity
    vector<vector<int>> M2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    int n2 = 3;
    cout << "Celebrity in Test Case 2: " << celebrity(M2, n2) << endl; // Expected Output: -1

    // Test case 3: Single person (trivial case)
    vector<vector<int>> M3 = {
        {0}
    };
    int n3 = 1;
    cout << "Celebrity in Test Case 3: " << celebrity(M3, n3) << endl; // Expected Output: 0

    // Test case 4: Celebrity exists with larger matrix
    vector<vector<int>> M4 = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };
    int n4 = 4;
    cout << "Celebrity in Test Case 4: " << celebrity(M4, n4) << endl; // Expected Output: 2

    return 0;
}