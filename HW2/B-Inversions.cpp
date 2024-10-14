#include <iostream>

using namespace std;

long long merge(int A[], int left, int mid, int right) {
    long long pairs = 0;
    int* temp = new int[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
            pairs += mid - i + 1;
        }
    }
    while (i <= mid) {
        temp[k++] = A[i++];
    }
    while (j <= right) {
        temp[k++] = A[j++];
    }
    for (int i = left; i <= right; i++) {
        A[i] = temp[i - left];
    }
    delete[] temp;
    return pairs;
}

long long merge_sort(int A[], int left, int right) {
    long long pairs = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        pairs += merge_sort(A, left, mid);
        pairs += merge_sort(A, mid + 1, right);
        pairs += merge(A, left, mid, right);
    }
    return pairs;
}

int main() {
    int N;
    long long pairs = 0;
    cin >> N;
    int* A = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    pairs = merge_sort(A, 0, N - 1);
    cout << pairs << endl;
    delete[] A;
    return 0;
}