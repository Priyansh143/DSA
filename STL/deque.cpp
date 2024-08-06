#include<iostream>
#include<deque>

using namespace std;

int main() {
    
    deque<int> d;

    d.push_back(1);
    d.push_front(2);


    // operations pop_back, pop_front, at(), front(), back(), empty() can be used as usual


    cout<<"erase function takes starting and ending position between which elements need to be deleted";
    d.erase(d.begin(), d.begin() +1);  //begin() function returns 
    
    //after erasing the memory of vector remains the same but the size of vector decreases.

    return 0;
}