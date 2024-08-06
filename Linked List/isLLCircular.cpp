#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int n) {
        this->data = n;
        this->next = NULL;
    }
};

bool isCircular(Node *head) {
        if(head==NULL){
            return true;
        }
        Node * temp=head;
        
        do{
            temp=temp->next;
        }
        while(temp!=head && temp!=NULL);
        if(temp==head){
            return true;
        }
        else{
            return false;
        }
    }