#include <iostream>
#include<stack>
using namespace std;

class Stack
{
public:
    int top;
    int *arr;
    int size;
    Stack(int size){
        this->size=size;
        arr = new int(size);
        top = -1; 
    }
    void push(int element){
        if (size - top >1)
        {   top++;
            arr[top]=element;
        }
        else
        {
            cout<<"stack overflow\n";
        }        
    }
    void pop(){
        if (top>=0)
        {
            top--;
        }
        else
        {
            cout<<"stack underflow\n";
        }
    }

    int peek(){
        if (top>=0)
        {
            return arr[top];
        }
        else{
            cout<<"stack is empty\n";
            return -1;
        }
        
    }
    bool isempty(){

        if (top == -1)
        {
            return true;
        }
        else{
            return false;
        }
        
    }
            
};

int main() {
    
    Stack s(5); // creation 

    // s.push(1);
    // s.push(2);
    // s.push(3);
    cout<<"top element: \n"<<s.peek();
    s.pop();
    cout<<"\ntop element: \n"<<s.peek();

    if (s.isempty())
    {
        cout<<"\nempty";
    }
    else{
        cout<<"\nnot empty";
    }
    cout<<endl<<"size: "<<s.size;
    
    return 0;
}