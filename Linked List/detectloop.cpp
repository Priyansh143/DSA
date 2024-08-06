#include <iostream>
#include <vector>
#include <map>
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

bool detectloop(Node* head){
    if (head==NULL)
    {
        return false;
    }
    map<Node*, bool> visited;

    Node* temp= head;

    while (temp != NULL)
    {
        if (visited[temp]==true)
        {   
            cout<<"present on element "<<temp->data<<endl;
            return true;
        }
        
        visited[temp]=true;
        temp=temp->next;
    }
    
    return false;
}

Node* floydDetectAlgo(Node * head){
    Node* slow=head;
    Node* fast=head;

    // if (head==NULL || head->next==NULL)
    // {
    //     return NULL;
    // }
    
    while (fast!=NULL)
    {
        slow=slow->next;
        // if (fast==NULL || fast->next==NULL)
        // {
        //     return ;
        // }
        fast=fast->next->next;
        if (slow==fast)
        {
            return slow;
        }
    }
    return slow;
    
}

Node* getStartingNode(Node* head){
    if (head==NULL)
    {
        return NULL;
    }
    Node* fast=floydDetectAlgo(head);
    Node* slow=head;
    while (fast!=slow)
    {
        slow=slow->next;
        fast=fast->next;
    }
    
    return slow;   
    
}

int main()
{

    Node *node1 = new Node(10);
    Node *tail = node1;
    Node *head = node1;
    insertAtHead(head, 12);
    insertAtHead(head, 14);
    insertAtTail(tail, 32);
    print(head);
    Node* test= head->next->next;
    tail->next=test;
    cout<<endl<<floydDetectAlgo(head);
    cout<<endl<<getStartingNode(head)->data;


    return 0;
}