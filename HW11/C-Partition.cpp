#include <iostream>
#include <vector>

using namespace std;

bool partition(vector<int> &nums) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    if (sum % 2 != 0) {
        return false;
    }
    sum /= 2;
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = sum; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[sum];
}

int main() {
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
    cout << (partition(nums) ? 1 : 0) << endl;
    return 0;
}