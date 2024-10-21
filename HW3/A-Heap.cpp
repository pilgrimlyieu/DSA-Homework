#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
    vector<int> heap;
    vector<int> idx;
    vector<int> pos;
    int size_ = 0;
    int pushed = 0;

    void min_heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int idx_min = (left < size_ && heap[left] < heap[i]) ? left : i;
        idx_min = (right < size_ && heap[right] < heap[idx_min]) ? right : idx_min;
        if (idx_min != i) {
            swap_element(i, idx_min);
            min_heapify(idx_min);
        }
    }

    void swap_element(int i, int j) {
        swap(heap[i], heap[j]);
        swap(pos[i], pos[j]);
        idx[pos[i]] = i;
        idx[pos[j]] = j;
    }

public:
    int size() {
        return size_;
    }

    int top() {
        return heap[0];
    }

    void push(int x) {
        heap.push_back(x);
        idx.push_back(size_);
        pos.push_back(pushed++);
        size_++;
        int i = size_ - 1;
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap_element(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }

    void pop() {
        swap_element(0, --size_);
        heap.pop_back();
        pos.pop_back();
        min_heapify(0);
    }

    void decrease(int i, int k) {
        int j = idx[i - 1];
        heap[j] = k;
        while (j > 0 && heap[(j - 1) / 2] > heap[j]) {
            swap_element(j, (j - 1) / 2);
            j = (j - 1) / 2;
        }
    }
};

int main() {
    MinHeap minHeap;
    string command;
    int x, y;
    while (cin >> command) {
        if (command == "push") {
            cin >> x;
            minHeap.push(x);
        } else if (command == "pop") {
            minHeap.pop();
        } else if (command == "top") {
            cout << minHeap.top() << endl;
        } else if (command == "size") {
            cout << minHeap.size() << endl;
        } else if (command == "decrease") {
            cin >> x >> y;
            minHeap.decrease(x, y);
        }
    }
    return 0;
}