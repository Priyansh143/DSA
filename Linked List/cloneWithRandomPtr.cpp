#include <iostream>
#include<vector>
#include <map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail,int n){
        Node* newnode= new Node(n);
        if(head==NULL){
            head= newnode;
            tail= newnode;
            return;
        }
        tail->next=newnode;
        tail=newnode;
    }
    Node* copyRandomList(Node* head)
    {
        Node* temp=head;
        Node* clonetail = NULL;
        Node* clonehead = NULL;
        map <Node*,Node*> oldtonew;

        while(temp!=NULL){
            insertAtTail(clonehead, clonetail, temp->val);
            temp=temp->next;
        }
        temp=head;
        Node* temp2= clonehead;

        while(temp!=NULL && temp2!=NULL){
            oldtonew[temp]=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
        temp=head;
        temp2=clonehead;
        while(temp!=NULL){
            temp2->random= oldtonew[temp->random];
            temp=temp->next;
            temp2=temp2->next;
        }
    return clonehead;
    }
};

int main() {
    
    return 0;
}