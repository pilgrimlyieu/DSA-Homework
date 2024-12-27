#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct child {
    int id;
    int score;
    int candy;
    child(int i, int s, int c) : id(i), score(s), candy(c) {}
    bool operator<(const child &c) const {
        return score < c.score;
    }
};

int main() {
    vector<child> children;
    vector<child> childrenSorted;
    int n, i = 0;
    while (cin >> n) {
        child c = child(i++, n, 1);
        children.push_back(c);
        childrenSorted.push_back(c);
    }
    sort(childrenSorted.begin(), childrenSorted.end());
    for (auto &child : childrenSorted) {
        int id = child.id;
        if (id > 0 && children[id].score > children[id - 1].score) {
            children[id].candy = max(children[id].candy, children[id - 1].candy + 1);
        }
        if (id < children.size() - 1 && children[id].score > children[id + 1].score) {
            children[id].candy = max(children[id].candy, children[id + 1].candy + 1);
        }
    }
    int sum = 0;
    for (auto &child : children) {
        sum += child.candy;
    }
    cout << sum << endl;
    return 0;
}