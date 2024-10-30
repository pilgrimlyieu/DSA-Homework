#include <iostream>
#include <vector>

using namespace std;

void printPreorder(vector<int>& inorder, int inbegin, int inend, vector<int>& postorder, int postbegin, int postend) {
    if (inbegin > inend || postbegin > postend) {
        return;
    }
    cout << postorder[postend] << " ";
    int i = inbegin;
    while (inorder[i] != postorder[postend]) {
        i++;
    }
    printPreorder(inorder, inbegin, i - 1, postorder, postbegin, postbegin + i - inbegin - 1);
    printPreorder(inorder, i + 1, inend, postorder, postbegin + i - inbegin, postend - 1);
}

int main() {
    vector<int> store, inorder, postorder;
    int n;
    while (cin >> n) {
        store.push_back(n);
    }
    for (int i = 0; i < store.size(); i++) {
        if (i < store.size() / 2) {
            inorder.push_back(store[i]);
        } else {
            postorder.push_back(store[i]);
        }
    }
    printPreorder(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    return 0;
}