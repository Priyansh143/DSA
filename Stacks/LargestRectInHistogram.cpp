#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> prevSmaller(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> arr2(n);
    for (int i = 0; i < n; i++)
    {
        while (arr[i] <= arr[s.top()] && s.top() != -1)
        {
            s.pop();
        }

        arr2[i] = s.top();
        s.push(i);
    }

    return arr2;
}
vector<int> nextSmaller(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> arr2(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (arr[i] <= arr[s.top()] && s.top() != -1)
        {
            s.pop();
        }

        arr2[i] = s.top();
        s.push(i);
    }
    return arr2;
}

int largestRectangleofHistogram(vector<int> &arr)
{
    int s = arr.size();
    int ans = INT_MIN;
    vector<int> next = nextSmaller(arr, s);
    vector<int> prev = prevSmaller(arr, s);

    for (int i = 0; i < s; i++)
    {
        int n = next[i];
        int p = prev[i];
        if (n == -1)
        {
            n = s;
        }
        int newarea = arr[i] * (n - p - 1);
        ans = max(newarea,ans);
    }
    return ans;
}

int main()
{
    // Test case 1
    vector<int> histogram1 = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area for histogram1: " << largestRectangleofHistogram(histogram1) << endl;
    // Expected Output: 10 (The largest rectangle is height 2 and width 5)

    // Test case 2
    vector<int> histogram2 = {4, 2, 0, 3, 2, 5};
    cout << "Largest Rectangle Area for histogram2: " << largestRectangleofHistogram(histogram2) << endl;
    // Expected Output: 6 (The largest rectangle is height 2 and width 3)

    // Test case 3
    vector<int> histogram3 = {1, 1, 1, 1, 1};
    cout << "Largest Rectangle Area for histogram3: " << largestRectangleofHistogram(histogram3) << endl;
    // Expected Output: 5 (The largest rectangle is height 1 and width 5)

    // Test case 4
    vector<int> histogram4 = {5, 6, 1, 2, 3};
    cout << "Largest Rectangle Area for histogram4: " << largestRectangleofHistogram(histogram4) << endl;
    // Expected Output: 10 (The largest rectangle is height 5 and width 2)

    return 0;
}