#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void moveZeroes(vector<int> &nums)
{

    int i = 0;

    for (int j = 0; j < nums.size(); j++)
    {

        if (nums[j] != 0)
        {

            if (i != j)
            {
                swap(nums, i, j);
            }
            i++;
        }
    }
}

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {0, 0, 1, 0, 3, 12};

    cout << "Original array: ";
    printArray(nums);

    moveZeroes(nums);

    cout << "Array after moving zeroes: ";
    printArray(nums);

    return 0;
}