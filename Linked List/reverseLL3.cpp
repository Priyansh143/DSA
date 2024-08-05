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

Node *reverse(Node *head)
{
    //base
    if (head == NULL || head->next==NULL)
    {
        return head;
    }
    
    Node*  smallList = reverse(head->next);

    head->next->next=head;
    head->next=NULL;
    return smallList;
}

int main()
{

    Node *first = new Node(10);
    Node *head = first;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    print(head);
    head= reverse(head);
    print(head);

    return 0;
}