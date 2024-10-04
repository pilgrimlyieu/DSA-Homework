#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

class CircularQueue {
public:
    int capacity;
    int size = 0;
    Node *sentinel = new Node();

    CircularQueue(int cap)  {
        capacity = cap;
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Overflow" << endl;
            return;
        }
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = sentinel->next;
        newNode->prev = sentinel;
        sentinel->next->prev = newNode;
        sentinel->next = newNode;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return;
        }
        Node *front = sentinel->prev;
        front->prev->next = sentinel;
        sentinel->prev = front->prev;
        delete front;
        size--;
    }

    void front() {
        if (isEmpty()) {
            cout << -1 << endl;
            return;
        }
        cout << sentinel->prev->data << endl;
    }

    void rear() {
        if (isEmpty()) {
            cout << -1 << endl;
            return;
        }
        cout << sentinel->next->data << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    int capacity;
    cin >> capacity;
    CircularQueue circularQueue(capacity);
    string command;
    int x;
    while (cin >> command) {
        if (command == "enqueue") {
            cin >> x;
            circularQueue.enqueue(x);
        } else if (command == "dequeue") {
            circularQueue.dequeue();
        } else if (command == "front") {
            circularQueue.front();
        } else if (command == "rear") {
            circularQueue.rear();
        } else if (command == "isEmpty") {
            cout << (circularQueue.isEmpty() ? "True" : "False") << endl;
        } else if (command == "isFull") {
            cout << (circularQueue.isFull() ? "True" : "False") << endl;
        }
    }
    return 0;
}