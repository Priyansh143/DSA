#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Node
{
private:
public:
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}

    Node(int n)
    {

        this->data = n;
        this->next = NULL;
    }
};

int length(Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i += 1;
        temp = temp->next;
    }
    return i;
}

void insertAtTail(Node *&tail, int data)
{
    
    Node *temp = new Node(data);
    if (tail==NULL)
    {
        tail=temp;
        return;
    }
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

void print(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverse(Node *&head)
{
    // base
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallList = reverse(head->next);

    head->next->next = head;
    head->next = NULL;
    return smallList;
}

Node* sum(Node *head1, Node *head2)
{
    int ans;
    Node *temp = reverse(head1);
    Node *temp2 = reverse(head2);
    Node *newhead = new Node(-1);
    Node *tail3 = newhead;
    int carry = 0;
    int digit = 0;

    while (temp != NULL || temp2 != NULL || carry != 0)
    {
        int val1 = 0;
        if (temp != NULL)
        {
            val1 = temp->data;
        }
        int val2 = 0;
        if (temp2 != NULL)
        {
            val2 = temp2->data;
        }

        int sum = val1 + val2 + carry;
        digit = sum % 10;
        carry = sum / 10;

        insertAtTail(tail3, digit);

        if (temp != NULL)
        {
            temp = temp->next;
        }
        if (temp2 != NULL)
        {
            temp2 = temp2->next;
        }
    }
    Node* newnode_temp= newhead;
    newhead=newhead->next;
    delete newnode_temp;
    cout<<endl;
    return reverse(newhead);
}

int main()
{
    Node *first = new Node(2);
    Node *head1 = first;
    Node *tail1 = first;
    Node *second = new Node(3);
    Node *head2 = second;
    Node *tail2 = second;

    insertAtTail(tail1, 4);
    // insertAtTail(tail1, 6);
    insertAtTail(tail1, 8);
    insertAtTail(tail2, 5);
    insertAtTail(tail2, 7);
    insertAtTail(tail2, 9);
    cout << "First list:";
    print(head1);
    cout << "\nSecond list:";
    print(head2);
    Node* temp = sum(head1, head2);
    cout << endl
         << "Sum = ";
    print(temp);
    return 0;
}