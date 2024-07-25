#include<iostream>
#include<array>

using namespace std;

int main() {
    int arr[3][3];
    int num;

    cout<<"Enter the elements: ";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    cout<<endl<<"Enter element to find: ";
    cin>>num;
    bool flag= false;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(arr[i][j]==num){
                flag= true;

            }
        }
        
    }
    if (flag){
        cout<<"\n Element Present";
    }
    else{
        cout<<"\n not present";
    }
    

    
    return 0;
}