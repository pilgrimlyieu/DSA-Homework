#include <iostream>
#include <vector>

using namespace std;

void _shell_sort(vector<int>& nums, int h) {
    for (int i = h; i < nums.size(); i++) {
        int key = nums[i];
        int j = i - h;
        while (j >= 0 && nums[j] > key) {
            nums[j + h] = nums[j];
            j -= h;
        }
        nums[j + h] = key;
    }
}

int main() {
    vector<int> a;
    int N, num;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        a.push_back(num);
    }
    for (int h = N / 2; h > 0; h /= 2) {
        _shell_sort(a, h);
    }
    for (int i : a) {
        cout << i << " ";
    }
    return 0;
}
