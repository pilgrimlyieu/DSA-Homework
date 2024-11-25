#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T, n, num;
    cin >> T;
    while (T--) {
        cin >> n;
        unordered_set<int> seen;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (seen.insert(num).second) {
                cout << num << " ";
            }
        }
        cout << endl;
    }
    return 0;
}