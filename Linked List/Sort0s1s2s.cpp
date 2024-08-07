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

void sortnums(Node * head){
    int countzero=0;
    int countone=0;
    int counttwo=0;
    Node* temp= head;
    while (temp!=NULL)
    {
        if (temp->data==0)
        {
            countzero++;
        }
        else if (temp->data==1)
        {
            countone++;
        }
        else{
            counttwo++;
        }
        
        temp=temp->next;
    }
    temp=head;
    while (temp!=NULL)
    {
        if (countzero>0)
        {
            temp->data=0;
            countzero--;
        }
        else if (countone>0)
        {
            temp->data=1;
            countone--;
        }
        else{
            temp->data=2;
            counttwo--;
        }
        temp=temp->next;  
    }
 
}

int main()
{

    Node *node1 = new Node(0);
    Node *head = node1;

    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 0);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    print(head);
    sortnums(head);
    print(head);

    return 0;
}