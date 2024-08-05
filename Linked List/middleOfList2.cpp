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

// int getLength(Node* &head){
    
//     Node* temp= head;
//     int len=0;
//     while (temp!=NULL)
//     {
//         len+=1;
//         temp=temp->next;
//     }
//     return len;
    

// }

Node* middle(Node* &head){

    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    
    if (head->next->next==NULL){
        return head->next;
    }
    


    
    Node* slow= head;
    Node*fast = head->next;
    while (fast != NULL)
    {
        fast=fast->next;
        if (fast != NULL)
        {
            fast=fast->next;

        }
        slow=slow->next;
        
    }
    return slow;
    
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;

    insertAtHead(head, 12);
    insertAtHead(head, 14);
    insertAtHead(head, 16);
    print(head);
    cout<<"\nMiddle Element: "<<middle(head)->data;

    return 0;
}