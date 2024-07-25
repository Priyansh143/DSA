#include<iostream>
#include<vector>
using namespace std;

vector<int> reversearr(vector<int>& v, int s){

    int st=0;
    while (st < s/2)
    {
        swap(v[st],v[s-st-1]);
        st++;
    }
    return v;
}
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int size = arr.size();

    cout << "Original array: ";
    printArray(arr);

    reversearr(arr, size);

    cout << "Reversed array: ";
    printArray(arr);

    return 0;
}