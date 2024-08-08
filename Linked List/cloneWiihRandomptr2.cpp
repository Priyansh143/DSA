#include <iostream>
#include<vector>

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
        if(head == NULL){
            return NULL;
        }
        //clone original list
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(clonehead, clonetail, temp->val);
            temp=temp->next;
        }
        Node * originalnode = head;
        Node * clonenode = clonehead;
        //add clonenodes in between original node
        while(originalnode!=NULL && clonenode!=NULL){
            Node* next =originalnode->next;
            originalnode->next = clonenode;
            originalnode = next;

            next = clonenode->next;
            clonenode->next = originalnode;
            clonenode= next;
        }
        originalnode=head;
        clonenode=originalnode->next;

        //random poiner setting for clone list
        originalnode = head;
        while(originalnode!=NULL){
            if(originalnode->next!=NULL){
                if(originalnode->random != NULL){
                    originalnode->next->random = originalnode->random->next;
                }
                else{
                    originalnode->next->random = originalnode->random;
                }
                originalnode=originalnode->next->next;
            }
            

        }
        //revert changes in step 2
        originalnode = head;
        clonenode = clonehead;
        while(originalnode!=NULL && clonenode!=NULL){
            
            originalnode->next = clonenode->next;
            originalnode = originalnode->next;
            if(originalnode!=NULL){
                clonenode -> next = clonenode->next->next;       
                clonenode = clonenode -> next;
            }
        }
        //return ans
        return clonehead;
    }
        
};

int main() {
    
    return 0;
}