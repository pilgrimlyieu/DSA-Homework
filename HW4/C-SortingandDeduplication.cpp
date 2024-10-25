// 🤡 我是小丑，看到大内存占用，自作聪明想到了课上讲的 External Merge Sort 🤡
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAX_VALUE = 100000000;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    bitset<MAX_VALUE + 1> bitmap;
    int num;
    while (cin >> num) {
        bitmap.set(num);
    }
    for (int i = 0; i <= MAX_VALUE; i++) {
        if (bitmap.test(i)) {
            cout << i << " ";
        }
    }
    return 0;
}