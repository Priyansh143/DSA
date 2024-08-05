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

void insertAtHead(Node *&head, Node *&tail, int data) {
    Node *temp = new Node(data);
    if (head == nullptr) {
        head = temp;
        tail = temp;
        temp->next = head;
    } else {
        temp->next = head;
        head = temp;
        tail->next = head;
    }
}

void print(Node *head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void insertAtTail(Node *&head, Node *&tail, int data) {
    Node *temp = new Node(data);
    if (head == nullptr) {
        head = temp;
        tail = temp;
        temp->next = head;
    } else {
        tail->next = temp;
        temp->next = head;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int pos) {
    if (pos == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    Node *newnode = new Node(data);
    Node *temp = head;
    int i = 1;

    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (temp->next == head && i < pos - 1) {
        insertAtTail(head, tail, data);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteAtPosition(Node *&head, Node *&tail, int pos) {
    if (head == nullptr) return; // Empty list case

    Node *temp = head;
    if (pos == 1) {
        if (head == tail) { // Only one node
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            tail->next = head;
            delete temp;
        }
        return;
    }

    Node *prev = nullptr;
    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == head) {
        if (temp == tail) {
            tail = prev;
        }
        prev->next = head;
        delete temp;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void deleteByValue(Node *&head, Node *&tail, int d) {
    if (head == nullptr) return; // Empty list case

    Node *temp = head;
    Node *prev = nullptr;

    if (temp->data == d) {
        if (head == tail) { // Only one node
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            tail->next = head;
            delete temp;
        }
        return;
    }

    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != d);

    if (temp == head) {
        cout << "\nElement not found" << endl;
        return;
    }

    if (temp->next == head) {
        prev->next = head;
        tail = prev;
        delete temp;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

int main() {
    Node *head = nullptr;
    Node *tail = nullptr;

    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 14);
    insertAtTail(head, tail, 16);
    insertAtTail(head, tail, 2);
    insertAtPosition(head, tail, 5, 3);
    insertAtPosition(head, tail, 5, 7);

    cout << "Before deletion:" << endl;
    print(head);

    deleteAtPosition(head, tail, 1);
    deleteAtPosition(head, tail, 6);
    deleteByValue(head, tail, 14);
    deleteByValue(head, tail, 5);

    cout << "After deletion:" << endl;
    print(head);

    return 0;
}
