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

Node *reverse(Node *&head)
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

int length(Node* head){
    Node* temp=head;
    int i=0;
    while (temp!=NULL)
    {
        i+=1;
        temp=temp->next;
    }
    return i;
}

bool isPalindrome(Node* head){

    if (head==NULL)
    {
        return false;
    }
    if (head->next==NULL)
    {
        return true;
    }
    
    
    int len=length(head);
    cout<<"\nlength is "<<len;
    int i=0;
    Node* temp = head;
    Node* temp2 = head;
    while (i<len/2)
    {
        i+=1;
        temp=temp->next;
    }
    temp= reverse(temp);
    cout<<endl;
    print(temp);
    Node* rev=temp;
    while (temp!=NULL)
    {
        if (temp->data==temp2->data)
        {
            temp=temp->next;
            temp2=temp2->next;
        }
        else{
            return false;
        }
        
    }
    reverse(rev);
    return true;
}

int main() {
    Node *node1 = new Node(10);
    Node *head = node1;

    // insertAtHead(head, 11);
    // insertAtHead(head, 12);
    // insertAtHead(head, 12);
    // insertAtHead(head, 10);
    // insertAtHead(head, 10);
    // insertAtHead(head, 15);
    print(head);
    cout<<endl;
    if (isPalindrome(head))
    {
        cout<<"palindrome";
    }
    else{
        cout<<"its not";
    }
    print(head);
    return 0;
}