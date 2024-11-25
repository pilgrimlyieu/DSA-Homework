// 本题 WA 未必真的就是 WA
// 一开始没去管 Clang Analyzer 的可能的内存泄漏的警告
// 即使检查了流程，确认了会有内存泄漏
// 因为 node 已存在，相当于创建了个新 node 更新了旧 node，旧 node 就悬空了
// 但由于感觉内存泄漏那跟 WA 也无关啊，于是就先没去管了
// 结果后面去打补丁就过了……
#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int key = 0;
    Node *parent = nullptr, *left = nullptr, *right = nullptr;

    Node(int key) : key(key) {}
};

class BST {
protected:
    Node* root = nullptr;

    Node* _search(Node* x, int key) {
        while (x != nullptr && x->key != key) {
            if (key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        return x;
    }

    Node* _search_parent(int key) {
        Node* x = root;
        Node* y = nullptr;
        while (x != nullptr && x->key != key) {
            y = x;
            if (key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        return y;
    }

    Node* _min(Node* x) {
        while (x->left != nullptr) {
            x = x->left;
        }
        return x;
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
    }

public:
    BST() : root(nullptr) {}

    BST(int data) : root(new Node(data)) {}

    Node* search(int key) {
        return _search(root, key);
    }

    void insert(int key) {
        Node* z = new Node(key);
        Node* parent = _search_parent(key);
        if (parent == nullptr) {
            if (root != nullptr) {
                delete z;
            } else {
                root = z;
            }
        } else if (key < parent->key && parent->left == nullptr) {
            parent->left = z;
            z->parent = parent;
        } else if (key > parent->key && parent->right == nullptr) {
            parent->right = z;
            z->parent = parent;
        } else {
            delete z;
        }
    }

    void remove(int key) {
        Node* z = search(key);
        if (z == nullptr) {
            return;
        }
        if (z->left == nullptr) {
            transplant(z, z->right);
        } else if (z->right == nullptr) {
            transplant(z, z->left);
        } else {
            Node* y = _min(z->right);
            if (y->parent != z) {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        delete z;
    }

    int larger(int key) {
        stack<Node*> s;
        Node* x = root;
        int count = 0;
        while (x != nullptr || !s.empty()) {
            while (x != nullptr) {
                s.push(x);
                x = x->right;
            }
            x = s.top();
            s.pop();
            if (x->key > key) {
                count++;
                x = x->left;
            } else {
                break;
            }
        }
        return count;
    }

    ~BST() {
        stack<Node*> s;
        Node* x = root;
        while (x != nullptr || !s.empty()) {
            while (x != nullptr) {
                s.push(x);
                x = x->left;
            }
            x = s.top();
            s.pop();
            Node* temp = x;
            x = x->right;
            delete temp;
        }
    }
};

int main() {
    BST bst;
    int N, command, x;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> command >> x;
        if (command == 1) {
            bst.insert(x);
        } else if (command == 2) {
            cout << (bst.search(x) != nullptr ? 0 : 1) << endl;
        } else if (command == 3) {
            bst.remove(x);
        } else if (command == 4) {
            cout << bst.larger(x) << endl;
        }
    }
    return 0;
}