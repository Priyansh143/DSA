#include <iostream>
#include<vector>
#include <math.h>
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

int sum(Node* head1, Node* head2){
    int len1 = length(head1);
    int len2 = length(head2);
    int ans;
    Node* temp= head1;
    Node* temp2=head2;
    while (len1>0){
    // {   cout<<endl<<"adding "<<
        ans+=(temp->data)*pow(10,len1-1);
        len1--;
        temp=temp->next;
    }
    while (len2>0)
    {
        ans+=(temp2->data)*pow(10,len2-1);
        len2--;
        temp2=temp2->next;
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
    cout<<endl<<"Sum = "<<sum(head1,head2);
    return 0;
}