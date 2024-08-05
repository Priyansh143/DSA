#include <iostream>
#include<vector>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    // ~Node(){
    //     if (this -> next != NULL)
    //     {
    //         delete next;
    //         next = NULL;
    //     }
        
    // }

};

void print(Node* &head){

    Node*temp=head;

    while (temp !=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
    
}

void insertAtHead(Node* &head, int data){

    Node* newnode= new Node(data);
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void insertAtTail(Node*&tail, int data){

    Node* newnode= new Node(data);
    tail->next=newnode;
    newnode->prev=tail;
    tail = newnode;
}

void insertAtPosition(Node* &head,Node* &tail, int pos, int data){

    //insert at head
    if (pos==1)
    {
        insertAtHead(head, data);
        return;
    }

    int i=1;
    Node * newnode = new Node(data);
    Node* temp = head;

    //Traversing List
    while(i<pos-1 && temp !=NULL){
        temp=temp->next;
        i++;
    }

    // For last position 
    if (temp->next == nullptr) {
        insertAtTail(tail, data);
        delete newnode;
        return;
    }

    //inserting in middle
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next= newnode;

}

void deleteAtPos(Node* &head,Node * &tail ,int pos){

    Node *temp = head;

    if (pos == 1)
    {
        // delete at head
        head->next->prev=NULL;
        head = head->next;
        delete temp;
        return;
    }
    else
    {
        // traversing
        for (int i = 1; temp != NULL && i < pos; i++)
        {
            temp = temp->next;
        } 
        //if position is more than size
        if (temp == nullptr)
        {
            return;
        }
        //deletion of last element
        if (temp->next==NULL)
        {
            temp->prev->next=NULL;
            tail = temp->prev;
            delete temp;
            return;
        }
        
        //deleting and updating node
        temp->prev->next=temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

int main() {

    Node *head= new Node(5);
    Node *tail=head;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtTail(tail, 7);
    insertAtTail(tail, 9);
    insertAtPosition(head,tail, 3, 1);
    insertAtPosition(head,tail, 1, 1);
    insertAtPosition(head,tail, 8, 6);
    deleteAtPos(head,tail, 4);
    deleteAtPos(head,tail, 7);
    deleteAtPos(head,tail, 1);
    print(head);

    return 0;
}