#include <iostream>
#include <vector>

using namespace std;

class Heap {
    vector<int> heap;
    bool max_heap = true;

    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (max_heap) {
            int idx_max = (left < size && heap[left] > heap[i]) ? left : i;
            idx_max = (right < size && heap[right] > heap[idx_max]) ? right : idx_max;
            if (idx_max != i) {
                swap(heap[i], heap[idx_max]);
                heapify(idx_max);
            }
            return;
        } else {
            int idx_min = (left < size && heap[left] < heap[i]) ? left : i;
            idx_min = (right < size && heap[right] < heap[idx_min]) ? right : idx_min;
            if (idx_min != i) {
                swap(heap[i], heap[idx_min]);
                heapify(idx_min);
            }
        }
    }

public:
    int size = 0;

    Heap(bool max_heap) : max_heap(max_heap) {}

    int top() {
        return heap[0];
    }

    void push(int x) {
        heap.push_back(x);
        size++;
        int i = size - 1;
        if (max_heap) {
            while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
                swap(heap[i], heap[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        } else {
            while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
                swap(heap[i], heap[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }
    }

    int pop() {
        int root = heap[0];
        swap(heap[0], heap[--size]);
        heap.pop_back();
        heapify(0);
        return root;
    }
};

int main() {
    int x;
    Heap max_heap(true);
    Heap min_heap(false);
    int median;
    cin >> median;
    bool is_even = false;
    while (cin >> x) {
        cout << median << endl;
        if (is_even) {
            if (x < median) {
                max_heap.push(x);
            } else {
                max_heap.push(median);
                if (!min_heap.size || x < min_heap.top()) {
                    median = x;
                } else {
                    median = min_heap.pop();
                    min_heap.push(x);
                }
            }
        } else {
            if (x < median) {
                min_heap.push(median);
                if (!max_heap.size || x > max_heap.top()) {
                    median = x;
                } else {
                    median = max_heap.pop();
                    max_heap.push(x);
                }
            } else {
                min_heap.push(x);
            }
        }
        is_even = !is_even;
    }
    cout << median << endl;
}