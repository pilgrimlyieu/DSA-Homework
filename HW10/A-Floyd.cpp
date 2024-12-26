#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
    vector<int> ws;
};

void floyd(vector<Node *> &nodes, int N) {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                nodes[i]->ws[j] = min(nodes[i]->ws[j], nodes[i]->ws[k] + nodes[k]->ws[j]);
            }
        }
    }
}

int main() {
    int N, M;
    vector<Node *> nodes;
    vector<int> pass;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        pass.push_back(n);
    }
    for (int i = 1; i <= N; i++) {
        Node *node = new Node();
        node->id = i;
        for (int j = 0; j < N; j++) {
            int danger;
            cin >> danger;
            node->ws.push_back(danger);
        }
        nodes.push_back(node);
    }
    floyd(nodes, N);
    long long danger = 0;
    for (int i = 0; i < M - 1; i++) {
        danger += nodes[pass[i] - 1]->ws[pass[i + 1] - 1];
    }
    cout << danger << endl;
    return 0;
}