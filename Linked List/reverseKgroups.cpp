#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
private:
public:
    int data;
    ListNode *next;

    ListNode(int n)
    {

        this->data = n;
        this->next = NULL;
    }
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    // Check if there are at least k nodes remaining in the list
    ListNode *temp = head;
    for (int i = 0; i < k; ++i)
    {
        if (temp == NULL)
        {
            return head;
        }
        temp = temp->next;
    }
    ListNode *ahead = NULL;
    ListNode *prev = NULL;
    ListNode *curr = head;
    int i = 0;
    while (i < k)
    {

        ahead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
        i++;
    }
    if (ahead != NULL)
    {

        head->next = reverseKGroup(ahead, k);
    }
    return prev;
}

void insertAtHead(ListNode *&head, int data)
{
    ListNode *temp = new ListNode(data);
    temp->next = head;
    head = temp;
}

void print(ListNode *&head)
{

    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    ListNode *first = new ListNode(10);
    ListNode *head = first;
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 65);
    insertAtHead(head, 34);
    insertAtHead(head, 23);
    insertAtHead(head, 89);
    print(head);
    head = reverseKGroup(head,3);
    print(head);

    return 0;
}