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

void reverseLL(Node *&head, Node *current, Node *prev)
{
    // base
    if (current == NULL)
    {
        head = prev;
        return;
    }

    Node *ahead = current->next;
    reverseLL(head, ahead, current);
    current->next = prev;
}

Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    reverseLL(head, curr, prev);
    return head;
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