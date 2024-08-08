#include <iostream>
#include<vector>
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

void insertAtTail(Node *&tail, int data)
{

    Node *temp = new Node(data);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
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

Node* solve(Node* first, Node* second){
    
    //if there is only 1 element in both list
    if (first->next==NULL)
    {
        first->next=second;
        return first;
    }
    
    Node* curr1=first;
    Node* curr2=second;
    Node* next = first->next;
    Node* next2 = curr2->next;

    while (next!=NULL && curr2!=NULL)
    {
        if ((curr2->data<=next->data) && (curr2->data>curr1->data))
        {
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next;
            curr1=curr2;
            curr2 = next2;
             
        }
        else
        {
            curr1 = next;
            next = next->next;

            if (next==NULL)
            {
                curr1->next=curr2;
                return first;
            }
            
        }  
    }
    return first;
    
}
Node * sortTwoList(Node* first, Node* second){
    Node* ans;
    if (first==NULL)
    {
        return second;
    }
    if (second==NULL)
    {
        return first;
    }
    Node* temp=second;
    if (first->data<=second->data)
    {
        ans=solve(first,second);
    }
    else{
        ans=solve(second,first);
    }
    return ans;
    
}

int main() {
    Node *first = new Node(2);
    Node *head1 = first;
    Node *tail1 = first;
    Node *second = new Node(3);
    Node* head2 = second;
    Node* tail2 = second;

    insertAtTail(tail1, 4);
    insertAtTail(tail1, 6);
    insertAtTail(tail1, 8);
    insertAtTail(tail2, 5);
    insertAtTail(tail2, 7);
    insertAtTail(tail2, 9);
    cout<<"First list:";
    print(head1);
    cout<<"\nSecond list:";
    print(head2);
    Node* ans = sortTwoList(head1,head2);
    print(ans);
    return 0;
    return 0;
}