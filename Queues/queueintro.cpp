#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Create a queue of integers
    queue<int> q;

    // Check if the queue is empty
    if (q.empty()) {
        cout << "The queue is empty." << endl;
    }

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Display the front element
    cout << "Front element: " << q.front() << endl;

    // Display the size of the queue
    cout << "Size of queue: " << q.size() << endl;

    // Dequeue an element
    cout << "Removing front element: " << q.front() << endl;
    q.pop();

    // Display the front element after popping
    cout << "New front element: " << q.front() << endl;

    // Display the size of the queue after popping
    cout << "Size of queue after pop: " << q.size() << endl;

    // Enqueue more elements
    q.push(40);
    q.push(50);

    // Display all elements in the queue
    cout << "Elements in the queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();  // Remove elements as we display them
    }
    cout << endl;

    return 0;
}
