#include<iostream>
#include<vector>

using namespace  std;

int main() {
    vector<int>v={1,2,3,4,5};

    //normal way of accessing vector elements byy indexes. 
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

    //BUt other complex data structures which are not continuosly stored in memory
    //need to accessed with iterators. 

    vector<int>::iterator it;  //this is vector iterator which can iterate only vector's elements address like pointers

    it=v.begin(); //this points to the starting position of the vector

    for ( it = v.begin(); it != v.end(); it++) //v.end() points to the position mext to last position    
    {
        cout<<*it;
    } 
    vector<pair<int,int>> p={{1,2},{5,2},{9,4},{3,8}};
    vector<pair<int,int>>::iterator ip;

    for (ip= p.begin(); ip != p.end(); ++ip)
    {
        cout<<endl<<ip->first<<" "<<ip->second;
    }

    //using auto keyword 
    vector<pair<int,int>> x={{1,6},{2,2},{7,4},{5,8}};
    cout<<"\n using auto keyword-\n";
    for(auto ix : x){
        
        cout<<ix.first<<","<<ix.second;
    }
    return 0;
}