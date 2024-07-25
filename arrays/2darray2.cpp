#include<iostream>
#include<array>

using namespace std;


void rowsum(int arr[3][3]){
    int sum=0;
    int ans=1;
    int check=0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum+=arr[i][j];
        }

        cout<<endl<<"Sum of "<<i+1<<"th row ="<<sum;
        if (sum>check){
            check=sum;
            ans=i+1;
        }

        sum=0;
        
    }
    cout<<"\n Row with largest sum = "<<ans;

}
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
    rowsum(arr);
}