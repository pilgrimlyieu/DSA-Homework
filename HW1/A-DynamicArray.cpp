#include <iostream>

using namespace std;

class DynamicArray {
public:
    int *data = new int[10];
    int size = 0;
    int capacity = 10;
    void append(int x) {
        if (size == capacity) {
            int *newData = new int[capacity * 2];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        data[size++] = x;
    }

    void set(int index, int x) {
        data[index] = x;
    }

    void erase(int index) {
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        if (size < capacity / 2) {
            int *newData = new int[capacity / 2];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity /= 2;
        }
    }

    int get(int index) {
        return data[index];
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray dynamicArray;
    string command;
    int index;
    int x;
    while (cin >> command) {
        if (command == "append") {
            cin >> x;
            dynamicArray.append(x);
        } else if (command == "set") {
            cin >> index >> x;
            dynamicArray.set(index, x);
        } else if (command == "erase") {
            cin >> index;
            dynamicArray.erase(index);
        } else if (command == "get") {
            cin >> index;
            cout << dynamicArray.get(index) << endl;
        } else if (command == "size") {
            cout << dynamicArray.getSize() << endl;
        } else if (command == "capacity") {
            cout << dynamicArray.getCapacity() << endl;
        } else if (command == "print") {
            dynamicArray.print();
        }
    }
    return 0;
}