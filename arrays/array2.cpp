#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reversearr(vector<int>& v, int s, int m){
    int start=find(v.begin(),v.end(),m)-v.begin()+1;
    int size=s-start;
    int end= s-1;
    int till=start+size/2;
    while(start<till){
        swap(v[start],v[end]);
        start++;
        end--;
    }
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
    
    int m=2;
    int index= find(arr.begin(),arr.end(), m)- arr.begin()+1;
    cout<<m<<endl;

    cout << "Original array: ";
    printArray(arr);


    reversearr(arr, size,m);

    cout << "Reversed array: ";
    printArray(arr);

    return 0;
}