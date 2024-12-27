#include <iostream>
#include <vector>

using namespace std;

int count(int a, vector<int> &coins) {
    vector<int> dp(a + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j <= a; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[a];
}

int main() {
    int a;
    cin >> a;
    vector<int> coins;
    int num;
    while (cin >> num) {
        coins.push_back(num);
    }
    vector<int> dp(a + 1, 0);
    cout << count(a, coins) << endl;
    return 0;
}