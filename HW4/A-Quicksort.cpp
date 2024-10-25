#include <iostream>
#include <vector>

using namespace std;

int _median_of_three(vector<int>& nums, int left, int right) {
    int mid = left + (right - left) / 2;
    if (nums[left] > nums[mid]) {
        swap(nums[left], nums[mid]);
    }
    if (nums[left] > nums[right]) {
        swap(nums[left], nums[right]);
    }
    if (nums[mid] > nums[right]) {
        swap(nums[mid], nums[right]);
    }
    swap(nums[mid], nums[right - 1]);
    return nums[right - 1];
}

int _partition(vector<int>& nums, int left, int right) {
    int pivot = _median_of_three(nums, left, right);
    int i = left;
    int j = right - 1;
    while (true) {
        while (nums[++i] < pivot) {}
        while (nums[--j] > pivot) {}
        if (i < j) {
            swap(nums[i], nums[j]);
        } else {
            break;
        }
    }
    swap(nums[i], nums[right - 1]);
    return i;
}

void _insert_sort(vector<int>& nums, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = nums[i];
        int j = i - 1;
        while (j >= left && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void _quick_sort(vector<int>& nums, int left, int right) {
    while (left < right) {
        if (right - left <= 10) {
            _insert_sort(nums, left, right);
            break;
        } else {
            int pivot = _partition(nums, left, right);
            if (pivot - left < right - pivot) {
                _quick_sort(nums, left, pivot - 1);
                left = pivot + 1;
            } else {
                _quick_sort(nums, pivot + 1, right);
                right = pivot - 1;
            }
        }
    }
}

void QuickSort(vector<int>& nums) {
    _quick_sort(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> a;
    int N, num;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        a.push_back(num);
    }
    QuickSort(a);
    for (int i : a) {
        cout << i << " ";
    }
    return 0;
}