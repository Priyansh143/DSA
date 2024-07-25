#include <iostream>
#include <vector>
using namespace std;

bool checksort(vector<int> &arr, int s)
{
    // base condition
    if (s == 1)
    {
        return true;
    }
    // recursive fucntion
    if (checksort(arr, s - 1))
    {
        if (arr[s-1] >= arr[s - 2])
        {
            return true;
        }
    }
    return false;
}

int main()
{

    vector<int> arr = {2,1,0};

    if (checksort(arr, arr.size()))
    {
        cout << "array sorted";
    }
    else
    {
        cout << "Not sorted";
    }

    return 0;
}