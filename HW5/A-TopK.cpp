#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& arr, int begin, int end) {
    int pivot = arr[end];
    int i = begin - 1;
    for (int j = begin; j < end; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

int Select(vector<int>& arr, int begin, int end, int K) {
    if (begin == end) {
        return arr[begin];
    }
    int q = Partition(arr, begin, end);
    if (q - begin == K - 1) {
        return arr[q];
    } else if (q - begin > K - 1) {
        return Select(arr, begin, q - 1, K);
    } else {
        return Select(arr, q + 1, end, K - q + begin - 1);
    }
}

int main() {
    int K, num;
    vector<int> arr;
    cin >> K;
    while (cin >> num) {
        arr.push_back(num);
    }
    cout << Select(arr, 0, arr.size() - 1, K) << endl;
    return 0;
}