#include <iostream>
#include<vector>
using namespace std;

class TwoStack
{
    int *arr;
    int top1;
    int top2;
    int size;

public:
    TwoStack(int s){

        this->size=s;
        top1=-1;
        top2=s;
        arr = new int[s];
    }
    void pushone(int elem){
        if (top2 - top1 > 1)
        {   top1++;
            arr[top1] = elem;
        }
        else{
            cout<<"stack overflow";
        }
        
    }
    void pushtwo(int elem){
        if (top2 - top1 > 1)
        {   top2--;
            arr[top2] = elem;
            cout<<"element pushed";
        }
        else{
            cout<<"stack overflow";
        }
    }
    void popone(){
        if (top1>=0)
        {
            top1--;
        }
        else{
            cout<<"stack underflow";
        }
    }
    void poptwo(){
        if (top2 <= size)
        {
            top2++;
        }
        else{
            cout<<"stack underflow";
        }
    }
    int peekone(){
        if (top1>=0)
        {
            return arr[top1];
        }
        else{
            cout<<"stack empty";
            return -1;
        }
    }
    int peektwo(){
        if (top2<=size)
        {
            return arr[top2];
        }
        else{
            cout<<"stack empty";
            return -1;
        }
    }
    bool isoneempty(){

        if (top1== -1)
        {
            return true;
        }
        else{
            return false;
        }       
    }
    bool istwoempty(){

        if (top2 == size)
        {
            return true;
        }
        else{
            return false;
        }       
    }
};


int main() {
    TwoStack s(5); // creation 

    s.pushone(1);
    s.pushone(2);
    s.pushtwo(3);
    s.pushtwo(1);
    s.pushtwo(7);
    cout<<"top element: \n"<<s.peekone();
    s.popone();
    cout<<"\ntop element: \n"<<s.peekone();
    cout<<"top element2: \n"<<s.peektwo();
    s.poptwo();
    cout<<"\ntop element2: \n"<<s.peektwo();

    if (s.isoneempty())
    {
        cout<<"\n one empty";
    }
    else{
        cout<<"\none not empty";
    }
    if (s.istwoempty())
    {
        cout<<"\n two empty";
    }
    else{
        cout<<"\n two not empty";
    }
    return 0;
}