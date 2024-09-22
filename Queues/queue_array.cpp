#include <iostream>
#include<vector>
using namespace std;

#define MAX 100 

class queue{
    private:
    int arr[MAX];
    int qfront;
    int rear;
    int size;
    public:

    queue(int size){
        qfront=0;
        rear=0;
        this->size=size;
        
    }
    bool isEmpty(){
        if (qfront == rear)
        {
            return true;
        }
        return false;       
    }
    void enqueue(int data){
        if (rear==size)
        {
            cout<<"Queue is full";
        }
        else{
            arr[rear]=data;
            rear++;
        }
        
    }
    void dequeue(){
        if (qfront == rear)
        {
            cout<<"Queue is empty";
        }
        else
        {
            int ans=arr[qfront];
            cout<<"Dequeued Element"<<ans<<endl;
            arr[qfront]=-1;
            qfront++;
        }
    }
    int front(){
        if (qfront==rear)
        {
            return -1;
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