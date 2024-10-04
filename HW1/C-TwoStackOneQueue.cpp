#include <iostream>

using namespace std;

class Queue {
    int Asize = 0;
    int Bsize = 0;
public:
    void enqueue() {
        Asize++;
        cout << "push A" << endl;
    }
    void dequeue() {
        if (Bsize == 0) {
            for (; Asize > 0; Asize--, Bsize++) {
                cout << "move A B" << endl;
            }
        }
        if (Bsize > 0) {
            Bsize--;
            cout << "pop B" << endl;
        }
    }
};

int main() {
    Queue queue;
    string command;
    while (cin >> command) {
        if (command == "enqueue") {
            queue.enqueue();
        } else if (command == "dequeue") {
            queue.dequeue();
        }
    }
}