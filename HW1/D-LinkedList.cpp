#include <iostream>

using namespace std;

class LinkedList {
    struct Node {
        int value;
        Node *next;
    };
    Node *head = nullptr;

    Node* deleteNode(Node* front, Node* current) {
        front->next = current->next;
        delete current;
        return front->next;
    }

public:
    void pushFront(int x) {
        if (head == nullptr) {
            head = new Node{x, nullptr};
        } else {
            Node *newNode = new Node{x, head};
            head = newNode;
        }
    }

    void pushBack(int x) {
        if (head == nullptr) {
            head = new Node{x, nullptr};
        } else {
            Node *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node{x, nullptr};
        }
    }

    bool search(int x) {
        Node *current = head;
        while (current != nullptr) {
            if (current->value == x) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void remove(int x) {
        if (head == nullptr) {
            return;
        }
        Node *front = head, *current = head->next;
        if (head->value == x) {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        while (current != nullptr) {
            if (current->value == x) {
                current = deleteNode(front, current);
            } else {
                front = current;
                current = current->next;
            }
        }
    }

    void print() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;
    string command;
    int x;
    while (cin >> command) {
        if (command == "pushFront") {
            cin >> x;
            linkedList.pushFront(x);
        } else if (command == "pushBack") {
            cin >> x;
            linkedList.pushBack(x);
        } else if (command == "search") {
            cin >> x;
            cout << linkedList.search(x) << endl;
        } else if (command == "remove") {
            cin >> x;
            linkedList.remove(x);
        } else if (command == "print") {
            linkedList.print();
        }
    }
    return 0;
}