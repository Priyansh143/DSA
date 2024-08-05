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

int getLength(Node* &head){
    
    Node* temp= head;
    int len=0;
    while (temp!=NULL)
    {
        len+=1;
        temp=temp->next;
    }
    return len;
    

}

int middle(Node* &head){
    int len=getLength(head);
    int pos=1;
    Node* temp=head;
    while (pos!=(len/2)+1)
        {
            temp=temp->next;
            pos++;
        }
    return temp->data;
    
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;

    insertAtHead(head, 12);
    insertAtHead(head, 14);
    insertAtHead(head, 16);
    print(head);
    cout<<"Length: "<<getLength(head);
    cout<<"\nMiddle Element: "<<middle(head);

    return 0;
}