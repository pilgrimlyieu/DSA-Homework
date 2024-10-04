#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v, m, s;
    int n;
    while (cin >> n) {
        v.push_back(n);
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        if (m.size() == 0) {
            m.push_back(v[i]);
        } else {
            while (v[i] < m.back()) {
                s.push_back(m.back());
                m.pop_back();
                if (m.size() == 0) {
                    break;
                }
            }
            m.push_back(v[i]);
        }
    }
    for (int i = m.size() - 1; i >= 0; i--) {
        s.push_back(m[i]);
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] < s[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}