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
    

};

void print(Node* &head, Node* &tail){

    Node*temp=head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
    
}

void insertAtHead(Node* &head, Node*&tail, int data){

    Node* newnode= new Node(data);
    newnode->next=head;
    head->prev=newnode;
    newnode->prev=tail;
    tail->next=newnode;
    head=newnode;
}

void insertAtTail(Node * &head, Node*&tail, int data){

    Node* newnode= new Node(data);
    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=head;
    tail = newnode;
    head->prev=tail;
}

void insertAtPosition(Node* &head,Node* &tail, int pos, int data){

    //insert at head
    if (pos==1)
    {
        insertAtHead(head,tail, data);
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
        insertAtTail(head, tail, data);
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
        head->next->prev=tail;
        head = head->next;
        tail->next=head;
        delete temp;
        return;
    }
    else
    {
        // traversing
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        } 
        //if position is more than size
        if (temp == nullptr)
        {
            return;
        }
        //deletion of last element
        if (temp->next==head)
        {
            temp->prev->next=head;
            tail = temp->prev;
            head->prev=tail;
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
    insertAtHead(head,tail, 3);
    insertAtHead(head,tail, 2);
    insertAtTail(tail,tail, 7);
    insertAtTail(tail,tail, 9);
    insertAtPosition(head,tail, 3, 1);
    insertAtPosition(head,tail, 1, 1);
    insertAtPosition(head,tail, 8, 6);
    deleteAtPos(head,tail, 4);
    deleteAtPos(head,tail, 7);
    deleteAtPos(head,tail, 1);
    print(head,tail);

    return 0;
}