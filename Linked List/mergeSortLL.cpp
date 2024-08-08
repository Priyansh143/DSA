#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    Node *next;
    int val;
    Node();
    Node(int val)
    {
        this->next = NULL;
        this->val = val;
    }
};

Node * midlist(Node *head)
{

    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;   
    }
    return slow;
}

void insertAtTail(Node *&tail, int val)
{

    Node *newnode = new Node(val);

    if (tail == NULL)
    {
        tail = newnode;
        return;
    }

    tail->next = newnode;
    tail = newnode;
}

void print(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    Node *sorted = new Node(-1);
    Node *temp = sorted;
    
    while (left != NULL && right != NULL)
    {
        if (left->val < right->val)
        {
            temp->next=left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next= right;
            temp = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        temp->next=left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next= right;
        temp = right;
        right = right->next;
    }

    sorted=sorted->next;
    return sorted;
}

Node *mergeSort(Node *head)
{
    // base
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // breaking list into two parts
    Node *mid = midlist(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // recursive calls for left and right part
    left = mergeSort(left);
    right = mergeSort(right);

    // MERGING SORTED LEFT AND RIGHT PART
    Node *sorted = merge(left, right);
    return sorted;
};

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 9);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    insertAtTail(tail, 4);
    insertAtTail(tail, 8);
    cout<<"before sort- ";
    cout<<endl;
    print(head);

    Node *sorted = mergeSort(head);

    cout<<endl;
    print(sorted);
    return 0;
}