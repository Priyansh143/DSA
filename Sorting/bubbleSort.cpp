#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{

    for (int j = n - 1; j > 0; j--)
    {

        bool swapped = false;

        for (int i = 0; i < j - 1; i++)
        {

            if (arr[i] > arr[i + 1])
            {

                swap(arr[i], arr[i + 1]);
                swapped=true;
            }
        }
        if (!swapped){
            break;
        }
    }
}
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}