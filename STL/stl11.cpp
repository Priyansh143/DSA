#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

 vector<int> v;
 v.push_back(1);
 v.push_back(3);
 v.push_back(42);
 v.push_back(5);
 v.push_back(23);



 cout<<binary_search(v.begin(),v.end(),5)<<endl;

 //elements should be sorted for binary search to work perfectly
 sort(v.begin(), v.end());
 cout<<binary_search(v.begin(),v.end(),5)<<endl;

    cout<<"finding 6: "<<binary_search(v.begin(),v.end(),6);

    //lower bound means, element 1st element greater than or equal to 5 in the vector
    //v.begin() is subtracted because lower_bound returns iterator to the element and 
    // when we subtract iterator from iterator we get interger telling distance between the 2 iterators
    cout<<"lower bound: "<<lower_bound(v.begin(),v.end(),5) - v.begin()<<endl;

    cout<<"upper bound: "<<upper_bound(v.begin(),v.end(),5) - v.begin()<<endl;

    //other operations
    int a=3;
    int b=8;
    cout<<min(a,b);
    cout<<max(a,b);

    swap(a,b);//other data structures in stl can also be swapped using this function

    string x ="sfgsg";
    reverse(x.begin(),x.end());
    cout<<"reversed: "<<x;

    //rotating vector

    rotate(v.begin(),v.begin(),v.end());
    cout<<"after rotate:";
    for (int i:v){
        cout<<i<<" ";
    }

    //sorting (based on introsort)
    sort(v.begin(),v.end());

    


return 0;
}