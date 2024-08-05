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

void insertAtPosition(Node *&head, int data, int pos)
{

    Node *newnode = new Node(data);
    Node *temp = head;
    int i = 1;

    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteAtPosition(Node *&head, int pos)
{

    int i = 1;
    Node *temp = head;
    Node *temp2;

    if (pos == 1)
    {
        // delete at head
        head = head->next;
        delete temp;
        return;
    }
    else
    {
        // traversing
        Node *prev = nullptr;
        for (int i = 1; temp != nullptr && i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        //if position is more than size
        if (temp == nullptr)
        {
            return;
        }
        //deleting and updating node
        prev->next = temp->next;
        delete temp;
    }
}

void deleteByValue(Node *&head, int d)
{

    Node *temp = head;
    Node *prev = NULL;
    if (temp->data == d)
    {
        head = head->next;
        delete temp;
        return;
    }
    while (temp != NULL && temp->data != d)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    delete temp;
}

int main()
{

    Node *node1 = new Node(10);
    Node *tail = node1;
    Node *head = node1;

    insertAtHead(head, 12);
    insertAtHead(head, 14);
    insertAtTail(tail, 16);
    insertAtTail(tail, 2);
    insertAtPosition(head, 5, 3);
    insertAtPosition(head, 5, 7);
    cout << "before deletion-" << endl;
    print(head);
    // deleteAtPosition(head, 4);

    cout << "after deletion-" << endl;
    deleteAtPosition(head, 1);
    deleteAtPosition(head, 6);
    deleteByValue(head, 14);
    deleteByValue(head, 5);

    print(head);

    return 0;
}