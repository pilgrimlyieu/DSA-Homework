// cin.peek() 害人不浅……
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {};
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
    int n = nums.size();
    int count = 0;
    int pos = 0;
    int farthest = 0;
    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == pos) {
            pos = farthest;
            count++;
            if (pos >= n - 1) {
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}