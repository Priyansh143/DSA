#include <iostream>
#include<vector>
using namespace std;

class Node
{

public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        next= NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void reverse(Node* &head){

    Node*prev=NULL;
    Node*current =head;
    Node*after;

    //if there is only 1 element
    if (current->next==NULL)
    {
        return;
    }
    

    while (current !=NULL){

        after=current->next;
        current->next=prev;
        prev=current;
        current = after;      
    }
    head=prev;
    
}

void print(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    Node* first=new Node(10);   
    Node* head= first;
    // insertAtHead(head,20);
    // insertAtHead(head,30);
    // insertAtHead(head,40);
    print(head);
    reverse(head);
    print(head);

    return 0;
}