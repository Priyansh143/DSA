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

void insertAtTail(Node *&tail, int data)
{

    Node *temp = new Node(data);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

void sortnums(Node * &head){
    Node* zerohead= new Node(0);
    Node* onehead= new Node(1);
    Node* twohead= new Node(2);
    Node* zerotail = zerohead;
    Node* onetail = onehead;
    Node* twotail = twotail;

    Node* temp= head;
    while (temp!=NULL)
    {
        if (temp->data==0)
        {
            insertAtTail(zerotail,0);
        }
        else if (temp->data==1)
        {
            insertAtTail(onetail,1);
        }
        else{
            insertAtTail(twotail,2);
        }
        temp=temp->next;
    }
    if (onehead->next!=NULL)
    {
        zerotail->next=onehead->next;
    }
    else{
        zerotail->next=twohead->next;
        return;
    }
    onetail->next=twohead->next;

    head=onehead->next;
    
    delete onehead;
    delete twohead;
    delete zerohead;
    return;
}

int main()
{

    Node *node1 = new Node(0);
    Node *head = node1;

    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    print(head);
    sortnums(head);
    print(head);

    return 0;
}