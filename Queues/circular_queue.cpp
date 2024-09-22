#include <iostream>
#include<vector>
using namespace std;

#define MAX 100 

class queue{
    private:
    int *arr;
    int qfront;
    int rear;
    int size;
    public:

    queue(int size){
        size=1000001;
        arr= new int[size];
        qfront=-1;
        rear=-1;
        this->size=size;
        
    }
    ~queue() {
        delete[] arr;
    }

    bool isEmpty(){
        
        return qfront == -1;
       
    }

    void enqueue(int data){
        if ( (qfront==0 && rear==size-1) || (rear==(qfront-1)%(size-1)) )
        {
            cout<<"Queue is full";
        }
        else if (qfront==-1)
        {
            arr[0]=data;
            rear=0;
            qfront=0;
        }
        else if (rear==size-1 && qfront!=0)
        {
            rear=0;
            arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;
        }  
        
    }
    void dequeue(){
        if (qfront == -1)
        {
            cout<<"Queue is empty";
        }
        else if (qfront == rear)
        {
            arr[qfront]=-1;
            qfront=-1;
            rear=-1;
        }
        else if (qfront==size-1)
        {
            qfront = 0;
            arr[qfront]=-1;
        }
        
        
    }
    int front(){
        if (qfront==-1)
        {
            return -1;
        }
        else if (qfront==rear==0){
            return arr[0];
        }
        else{
            return arr[qfront];
        }
        
    }
    
};

int main() {
     
    queue q(5); // Example size of 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element: " << q.front() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Front element after two dequeues: " << q.front() << endl;

    return 0;
}