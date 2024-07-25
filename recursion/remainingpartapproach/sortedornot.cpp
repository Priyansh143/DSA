#include <iostream>
#include <vector>
using namespace std;

bool checksort(int *arr, int size)
{
    // base condition
    if (size == 0 || size==1)
    {
        return true;
    }
    // recursive fucntion
    
    if (arr[0]>arr[1])
    {
        return false;
    }
    else{
        bool remainingPart= checksort(arr + 1, size -1);
        return remainingPart;
    }
    
}

int main()
{

    int arr[3] = {2,1,0};
    int size=3;
    if (checksort(arr, size))
    {
        cout << "array sorted";
    }
    else
    {
        cout << "Not sorted";
    }

    return 0;
}