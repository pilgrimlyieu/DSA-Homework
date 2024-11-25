#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int parent;
    int rank;
};

class DisjointSet {
    vector<Node> nodes;

public:
    DisjointSet(int n) : nodes(n) {
        for (int i = 0; i < n; i++) {
            makeSet(i);
        }
    }

    void makeSet(int x) {
        nodes[x] = {x, 0};
    }

    int find(int x) {
        if (nodes[x].parent != x) {
            nodes[x].parent = find(nodes[x].parent);
        }
        return nodes[x].parent;
    }

    void unionSet(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) {
            return;
        }
        if (nodes[x_root].rank < nodes[y_root].rank) {
            nodes[x_root].parent = y_root;
        } else if (nodes[x_root].rank > nodes[y_root].rank) {
            nodes[y_root].parent = x_root;
        } else {
            nodes[y_root].parent = x_root;
            nodes[x_root].rank++;
        }
    }

    int connected(int x, int y) {
        return find(x) == find(y) ? 1 : 0;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    DisjointSet ds(M + 1);
    for (int i = 0; i < N; ++i) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            ds.unionSet(x, y);
        } else if (op == 2) {
            cout << ds.connected(x, y) << endl;
        }
    }
    return 0;
}