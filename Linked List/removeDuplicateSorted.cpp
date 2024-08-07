#include <iostream>
#include <vector>
using namespace std;

class Node
{
private:
public:
    int data;
    Node *next;

    Node();

    Node(int n)
    {

        this->data = n;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
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

void removeDup(Node * head)
{
    if (head == NULL || head->next==NULL)
    {
        return;
    }
    
    Node* prev= head;
    Node* next= head->next;
    while (next != NULL)
    {
        if (prev->data==next->data)
        {
            Node* temp=next->next;
            prev->next=temp;
            delete next;
            next=temp;  
        }
        else{
            prev=prev->next;
            next=next->next;
        }
    }
}   

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;

    insertAtHead(head, 10);
    insertAtHead(head, 12);
    insertAtHead(head, 16);
    insertAtHead(head, 16);
    insertAtHead(head, 15);
    insertAtHead(head, 15);
    print(head);
    removeDup(head);
    print(head);
    return 0;
}