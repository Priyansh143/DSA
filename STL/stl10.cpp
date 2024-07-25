#include<iostream>
#include<map>

using namespace std;

int main() {
    map<int,string>m;
    m[1]="Goddess";
    m[4]="Everything";
    m[3]="is";
    m[2]="Versona";

    m.insert( {5,"to me"} );
    
    for(auto i:m){
        cout<<i.first<<i.second;
        cout<<endl;
    }

    cout<<"finding 13: "<< m.count(4)<<endl;

    // m.erase(5);
    // cout<<"after erase: "<<endl;
    // for(auto i:m){
    //     cout<<i.first<<i.second;
    //     cout<<endl;
    // }

    auto it = m.find(1);
    for(auto i=it; i!=m.end();i++){
        cout<<i->first; 
    }
    return 0;
}